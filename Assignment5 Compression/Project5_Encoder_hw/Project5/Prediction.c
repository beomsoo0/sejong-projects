#include "Encoder.h"

void Prediction_Func(UChar* buf, Int BLK, Int Blk_Row, Int Blk_Col, Img_Buf* img)
{
	UChar* Ref, * Src;
	UChar Ref_pix[17] = { 0 };

	Int Sad[Max_Mode_num] = { 0 };
	Int Sort[Max_Mode_num] = { 0 };
	Int Best_Sad, tmp, BestMode;
	Int Dia_Pos;
	Int DC_Avr = 0;

	Int* Dc, * Ver, * Hor, * Dia;
	Int* Resi_Dc, * Resi_Ver, * Resi_Hor, * Resi_Dia;

	int i, j = 0;

	Dc  = (Int*)calloc(BLK * BLK, sizeof(Int));
	Ver = (Int*)calloc(BLK * BLK, sizeof(Int));
	Hor = (Int*)calloc(BLK * BLK, sizeof(Int));
	Dia = (Int*)calloc(BLK * BLK, sizeof(Int));

	Resi_Dc = (Int*)calloc(BLK * BLK, sizeof(Int));
	Resi_Ver = (Int*)calloc(BLK * BLK, sizeof(Int));
	Resi_Hor = (Int*)calloc(BLK * BLK, sizeof(Int));
	Resi_Dia = (Int*)calloc(BLK * BLK, sizeof(Int));

	BestMode = 0;
	Src = img->Pad_Rec_img;
	Ref = Src + ((Blk_Row * BLK) * img->info.P_stride + (Blk_Col * BLK));


	//예측을 위한 참조 화소 유도
	
	//
	if (Blk_Row == 0 && Blk_Col == 0) {
		for (i = 0; i <= 2 * BLK; i++) {
			Ref_pix[i] = 128;
		}
	}
	else if (Blk_Row == 0 && Blk_Col != 0) {
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = 128;
		}
		for (i = 0; i < BLK; i++) {
			Ref_pix[BLK + i] = *(Ref + (BLK - 1 - i) * img->info.P_stride - 1);
		}
		Ref_pix[2 * BLK] = 128;
	}
	else if (Blk_Row == 0 && Blk_Col != 0) {
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = *(Ref - 1 * img->info.P_stride + j);
		}
		for (i = 0; i < BLK; i++) {
			Ref_pix[BLK + i] = 128;
		}
		Ref_pix[2 * BLK] = 128;
	}
	else{
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = *(Ref - 1 * img->info.P_stride + j);
		}
		for (i =0; i < BLK; i++) {
			Ref_pix[BLK + i] = *(Ref + (BLK - 1 - i) * img->info.P_stride - 1);
		}
		Ref_pix[2 * BLK] = *(Ref - 1 * img->info.P_stride - 1);
	}
	
		
	//각 모드별로 예측 수행

	//
	for (i = 0; i < 2 * BLK; i++) {
		DC_Avr += Ref_pix[i];
	}
	DC_Avr >>= (BLK / 2);

	for (i = 0; i < BLK; i++) {
		for (j = 0; j < BLK; j++) {
			*(Ver + BLK * i + j) = Ref_pix[j];
			*(Hor + BLK * i + j) = Ref_pix[2 * BLK - 1 - i];
			*(Dc + BLK * i + j) = DC_Avr;

			Dia_Pos = i - j;
			if (Dia_Pos == 0) {
				*(Dia + BLK * i + j) = Ref_pix[2 * BLK];
			}
			else if (Dia_Pos < 0) {
				*(Dia + BLK * i + j) = Ref_pix[Dia_Pos + 1];
			}
			else if (Dia_Pos > 0) {
				*(Dia + BLK * i + j) = Ref_pix[2 * BLK - Dia_Pos];
			}
		}
	}



	
	for (Int i = 0; i < BLK * BLK; i++) //SAD 계산 및 잔차블록 생성
	{
		Sad[0] += abs(Resi_Ver[i] = buf[i] - Ver[i]);
		Sad[1] += abs(Resi_Hor[i] = buf[i] - Hor[i]);
		Sad[2] += abs(Resi_Dia[i] = buf[i] - Dia[i]);
		Sad[3] += abs(Resi_Dc[i] = buf[i] - Dc[i]);
	}

	for (Int i = 0; i < Max_Mode_num; i++)
		Sort[i] = Sad[i];

	for (Int i = 1; i < Max_Mode_num; i++)
	{
		for (tmp = Sort[i], Best_Sad = i; Best_Sad > 0; Best_Sad--)
		{
			if (Sort[Best_Sad - 1] > tmp)
				Sort[Best_Sad] = Sort[Best_Sad - 1];
			else break;
		}
		Sort[Best_Sad] = tmp;
	}

	for (Int i = 0; i < Max_Mode_num; i++)
		if (Sort[0] == Sad[i])
		{
			BestMode = i;
			break;
		}
	
	img->info.Best_Mode = BestMode;
	switch (BestMode)
	{
	case 3:
		memcpy(img->Resi_blk, Resi_Dc, BLK * BLK * sizeof(Int));
		break;
	case 0:
		memcpy(img->Resi_blk, Resi_Ver, BLK * BLK * sizeof(Int));
		break;
	case 1:
		memcpy(img->Resi_blk, Resi_Hor, BLK * BLK * sizeof(Int));
		break;
	case 2:
		memcpy(img->Resi_blk, Resi_Dia, BLK * BLK * sizeof(Int));
		break;
	}

	free(Dc);
	free(Ver);
	free(Hor);
	free(Dia);

	free(Resi_Dc);
	free(Resi_Ver);
	free(Resi_Hor);
	free(Resi_Dia);
}

void Reconstruct_Func(UChar* buf, Int BLK, Int Blk_Row, Int Blk_Col, Img_Buf* img)
{
	UChar Best[64]; //예측 블록
	UChar* Ref, * Src;

	UChar Ref_pix[17];

	Int Dia_Pos;
	Int DC_Avr = 0;

	int i, j = 0;

	Src = img->Pad_Rec_img;
	Ref = Src + ((Blk_Row * BLK) * img->info.P_stride + (Blk_Col * BLK));

	//예측을 위한 참조 화소 유도

	//
	if (Blk_Row == 0 && Blk_Col == 0) {
		for (i = 0; i <= 2 * BLK; i++) {
			Ref_pix[i] = 128;
		}
	}
	else if (Blk_Row == 0 && Blk_Col != 0) {
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = 128;
		}
		for (i = 0; i < BLK; i++) {
			Ref_pix[BLK + i] = *(Ref + (BLK - 1 - i) * img->info.P_stride - 1);
		}
		Ref_pix[2 * BLK] = 128;
	}
	else if (Blk_Row == 0 && Blk_Col != 0) {
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = *(Ref - 1 * img->info.P_stride + j);
		}
		for (i = 0; i < BLK; i++) {
			Ref_pix[BLK + i] = 128;
		}
		Ref_pix[2 * BLK] = 128;
	}
	else {
		for (j = 0; j < BLK; j++) {
			Ref_pix[j] = *(Ref - 1 * img->info.P_stride + j);
		}
		for (i = 0; i < BLK; i++) {
			Ref_pix[BLK + i] = *(Ref + (BLK - 1 - i) * img->info.P_stride - 1);
		}
		Ref_pix[2 * BLK] = *(Ref - 1 * img->info.P_stride - 1);
	}



	//예측 블록 생성

	if (img->info.Best_Mode == DC)
	{
		for (i = 0; i < 2 * BLK; i++) {
			DC_Avr += Ref_pix[i];
		}
		DC_Avr >>= (BLK / 2);

		for (i = 0; i < BLK; i++) {
			for (j = 0; j < BLK; j++) {
				*(Best + BLK * i + j) = DC_Avr;
			}
		}
	}

	else if (img->info.Best_Mode == VERTICAL)
	{
		for (i = 0; i < BLK; i++) {
			for (j = 0; j < BLK; j++) {
				*(Best + BLK * i + j) = Ref_pix[j];
			}
		}
	}

	else if (img->info.Best_Mode == HORIZONTAL)
	{
		for (i = 0; i < BLK; i++) {
			for (j = 0; j < BLK; j++) {
				*(Best + BLK * i + j) = Ref_pix[2 * BLK - 1 - i];
			}
		}
	}

	else
	{
		for (i = 0; i < BLK; i++) {
			for (j = 0; j < BLK; j++) {
				Dia_Pos = i - j;
				if (Dia_Pos == 0) {
					*(Best + BLK * i + j) = Ref_pix[2 * BLK];
				}
				else if (Dia_Pos < 0) {
					*(Best + BLK * i + j) = Ref_pix[Dia_Pos + 1];
				}
				else if (Dia_Pos > 0) {
					*(Best + BLK * i + j) = Ref_pix[2 * BLK - Dia_Pos];
				}
			}
		}
	}







    //복원 블록 생성
	for (Int i = 0; i < BLK; i++)
		for (Int j = 0; j < BLK; j++)
			buf[i * BLK + j] = img->Resi_blk[i * BLK + j] + Best[i * BLK + j];
}