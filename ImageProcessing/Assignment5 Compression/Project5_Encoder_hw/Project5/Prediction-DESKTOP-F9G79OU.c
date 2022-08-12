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

	for (int i = 0; i < BLK - 1; i++) {
		Ref_pix[i] = *(buf + (-1) * BLK + (i + 1));
	}
	for (int j = BLK; j >= 0; j--) {
		Ref_pix[BLK -1 + j] = *(buf + j * BLK + (-1));
	}











		
	//각 모드별로 예측 수행

	//













	
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

	Src = img->Pad_Rec_img;
	Ref = Src + ((Blk_Row * BLK) * img->info.P_stride + (Blk_Col * BLK));

	//예측을 위한 참조 화소 유도
	





	//예측 블록 생성
	if (img->info.Best_Mode == DC)
	{
	





	}

	else if (img->info.Best_Mode == VERTICAL)
	{

	}





	else if (img->info.Best_Mode == HORIZONTAL)
	{

	}








	else
	{

	}







    //복원 블록 생성
	for (Int i = 0; i < BLK; i++)
		for (Int j = 0; j < BLK; j++)
			buf[i * BLK + j] = img->Resi_blk[i * BLK + j] + Best[i * BLK + j];
}