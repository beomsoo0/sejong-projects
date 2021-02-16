#include "DFT.h"

void IDFT_Func(Double* Mag_buf, Double* Pha_buf, Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img)
{
	Double* DFT_Real;
	Double* DFT_Imag;
	Double Recon_R;

	DFT_Real = (Double*)calloc(BLK * BLK, sizeof(Double));
	DFT_Imag = (Double*)calloc(BLK * BLK, sizeof(Double));

	for (Int i = 0; i < BLK; i++)
	{
		for (Int j = 0; j < BLK; j++)
		{
			DFT_Real[i * BLK + j] = Mag_buf[i * BLK + j] * cos(Pha_buf[i * BLK + j]);
			DFT_Imag[i * BLK + j] = Mag_buf[i * BLK + j] * sin(Pha_buf[i * BLK + j]);
		}
	}

	for (Int i = 0; i < BLK; i++)
	{
		for (Int j = 0; j < BLK; j++)
		{
			Recon_R = 0;
			for (Int k = 0; k < BLK; k++)
			{
				for (Int l = 0; l < BLK; l++)
				{
					Recon_R += DFT_Real[k * BLK + l] * cos(2.0 * PI * (double)(i * k + j * l) / (double)BLK) + DFT_Imag[k * BLK + l] * sin(2.0 * PI * (double)(i * k + j * l) / (double)BLK);

				}

			}

			if (Recon_R < 0)
				Recon_R = (int)(Recon_R - 0.5);

			else
				Recon_R = (int)(Recon_R + 0.5);

			img->Rec_img[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = CLIP(Recon_R);
		}
	}

	free(DFT_Real);
	free(DFT_Imag);
}


#define convert(x, y)	sqrt( (Double)(x*x + y*y) );
#define D0				32.0
#define N0				4.0

void LPF(Img_Buf* img, UChar* Real_buf, UChar* Imag_buf, Int Blk_Row, Int Blk_COl)
{
	UInt	i, j;
	UInt	Tmpx, Tmpy;
	Double	FliterCoeff;
	Double  Coordinate;

	for (i = 0; i < img->info.height; i++)
	{
		if (i >= img->info.width / 2)
			Tmpy = i - (img->info.width / 2);
		else
			Tmpy = i + (img->info.width / 2);

		for (j = 0; j < img->info.width; j++)
		{
			if (i >= img->info.height / 2)
				Tmpx = i - (img->info.height / 2);
			else
				Tmpx = i + (img->info.height / 2);

			Coordinate = convert((Tmpx - (img->info.width / 2)), (Tmpy - (img->info.height / 2)));
			FliterCoeff = 1.0 / (1.0 + pow(Coordinate / D0, 2 * N0));

			Real_buf[i * img->info.height + j] *= FliterCoeff;
			Imag_buf[i * img->info.height + j] *= FliterCoeff;
		}
	}
}

void DFT_Func(UChar* buf, Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img)
{
	Double* DFT_Real;
	Double* DFT_Imag;
	Double* Mag_blk;
	Double* Pha_blk;

	DFT_Real = (Double*)calloc(BLK * BLK, sizeof(Double));
	DFT_Imag = (Double*)calloc(BLK * BLK, sizeof(Double));
	Mag_blk  = (Double*)calloc(BLK * BLK, sizeof(Double));
	Pha_blk  = (Double*)calloc(BLK * BLK, sizeof(Double));


	Double C, Temp, Spec;											//LPF 5줄
	Double* SpecTmp;
	UChar* Shuffling;

	SpecTmp = (Double*)calloc(BLK * BLK, sizeof(Double));
	Shuffling = (UChar*)calloc(BLK * BLK, sizeof(UChar));

	//실수부 허수부 나누기
	for (Int i = 0; i < BLK; i++)														
	{
		for (Int j = 0; j < BLK; j++)
		{
			for (Int k = 0; k < BLK; k++)
			{
				for (Int l = 0; l < BLK; l++)									
				{
					DFT_Real[i * BLK + j] += (double)buf[k * BLK + l] * cos(2.0 * PI * (double)(i * k + j * l) / (double)BLK); 
					DFT_Imag[i * BLK + j] += (double)buf[k * BLK + l] * sin(2.0 * PI * (double)(i * k + j * l) / (double)BLK);
				}
			}
			DFT_Real[i * BLK + j] = DFT_Real[i * BLK + j] / (BLK * BLK); 
			DFT_Imag[i * BLK + j] = DFT_Imag[i * BLK + j] / (BLK * BLK); 
		}
	}

	if (BLK == img->info.width && BLK == img->info.height && FilterFlag == 'y')
		LPF(img, DFT_Real, DFT_Imag, Blk_Row, Blk_COl);


	// Magnitude, Phase 생성
	for (Int i = 0; i < BLK; i++)
	{
		for (Int j = 0; j < BLK; j++)
		{
			Mag_blk[i * BLK + j] = sqrt(DFT_Real[i * BLK + j] * DFT_Real[i * BLK + j] + DFT_Imag[i * BLK + j] * DFT_Imag[i * BLK + j]);
			Pha_blk[i * BLK + j] = atan2(DFT_Imag[i * BLK + j], DFT_Real[i * BLK + j]);
		}
	}

	for (Int i = 0; i < BLK; i++)
	{
		for (Int j = 0; j < BLK; j++)
		{
			img->Real_img[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = DFT_Real[i * BLK + j];
			img->Imag_img[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = DFT_Imag[i * BLK + j];
			img->Magnitude[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = Mag_blk[i * BLK + j];
			img->Phase[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = Pha_blk[i * BLK + j];
		}
	}

	if (BLK == img->info.width && BLK == img->info.height)
	{
		C = hypot(img->Real_img[(Blk_Row * BLK) + (Blk_COl * (img->info.width + (img->info.width % BLK)) * BLK)], img->Imag_img[(Blk_Row * BLK) + (Blk_COl * (img->info.width + (img->info.width % BLK)) * BLK)]);
		for (Int i = 0; i < BLK; i++)
		{
			Spec = 0;
			for (Int j = 0; j < BLK; j++)
			{
				Temp = hypot(img->Real_img[(Blk_Row * BLK) + (Blk_COl * (img->info.width + (img->info.width % BLK)) * BLK) + ((img->info.width + (img->info.width % BLK)) * i) + j], img->Imag_img[(Blk_Row * BLK) + (Blk_COl * (img->info.width + (img->info.width % BLK)) * BLK) + ((img->info.width + (img->info.width % BLK)) * i) + j]);
				Spec = (C * log(1.0 + abs(Temp))) < 0.0 ? 0.0 : (C * log(1.0 + abs(Temp))) > 255.0 ? 255.0 : (C * log(1.0 + abs(Temp)));
				SpecTmp[i * BLK + j] = Spec;
			}
		}

		// 셔플링
		for (Int i = 0; i < BLK; i += (BLK / 2))
		{
			for (Int j = 0; j < BLK; j += (BLK / 2))
			{
				for (Int k = 0; k < (BLK / 2); k++)
				{
					for (Int l = 0; l < (BLK / 2); l++)
					{
						Shuffling[img->info.width * (k + i) + (l + j)] = (UChar)SpecTmp[img->info.width * (255 - k + i) + (255 - l + j)];
					}
				}
			}
		}
	}

	FILE* fp;
	fopen_s(&fp, "DFT_Spectrum.raw", "wb");
	if (BLK == img->info.width && BLK == img->info.height)
		fwrite(Shuffling, sizeof(UChar), BLK * BLK, fp);

	free(SpecTmp);
	free(Shuffling);

	fclose(fp);



	free(DFT_Real);
	free(DFT_Imag);
	free(Mag_blk);
	free(Pha_blk);
}

void DFT_Process(Img_Buf* img)
{
	Int BLK = Blk_SIZE;

	UChar* Focus_TMP;
	UChar* TMP;
	UChar* Padding_buf;

	if (BLK == img->info.width && BLK == img->info.height)
	{
		printf("LPF를 적용 하시겠습니까?(y or n)");
		printf("\n%c", FilterFlag);
		system("cls");
	}



	img->Rec_img   = (UChar* )calloc(img->info.width * img->info.height, sizeof(UChar ));
	img->Real_img  = (Double*)calloc(img->info.width * img->info.height, sizeof(Double));
	img->Imag_img  = (Double*)calloc(img->info.width * img->info.height, sizeof(Double));
	img->Magnitude = (Double*)calloc(img->info.width * img->info.height, sizeof(Double));
	img->Phase     = (Double*)calloc(img->info.width * img->info.height, sizeof(Double));

	img->info.Ori_stride = img->info.width;

	//DFT
	Padding_buf = (UChar*)calloc(BLK * BLK, sizeof(UChar));
	for (Int Blk_Row = 0; Blk_Row < img->info.height / BLK; Blk_Row++)
	{
		for (Int Blk_COl = 0; Blk_COl < img->info.width / BLK; Blk_COl++)
		{
			memset(Padding_buf, 0, sizeof(UChar) * BLK * BLK);

			Focus_TMP = img->Ori_img + ((Blk_Row * BLK) * img->info.Ori_stride + (Blk_COl * BLK));					//왼쪽위
			for (int k = 0; k < BLK; k++)
				for (int l = 0; l < BLK; l++)
				{
					TMP = Focus_TMP + (k * img->info.Ori_stride + l);
					Padding_buf[k * BLK + l] = TMP[0];
				}

			DFT_Func(Padding_buf, BLK, Blk_Row, Blk_COl, img);
		}
	}
	free(Padding_buf);

	//IDFT
	Double* Mag_Focus_TMP;
	Double* Mag_TMP;
	Double* Mag_buf;

	Double* Pha_Focus_TMP;
	Double* Pha_TMP;
	Double* Pha_buf;

	Mag_buf = (Double*)calloc(BLK * BLK, sizeof(Double));
	Pha_buf = (Double*)calloc(BLK * BLK, sizeof(Double));
	for (Int Blk_Row = 0; Blk_Row < img->info.height / BLK; Blk_Row++)
	{
		for (Int Blk_COl = 0; Blk_COl < img->info.width / BLK; Blk_COl++)
		{
			memset(Mag_buf, 0, sizeof(Double) * BLK * BLK);
			memset(Pha_buf, 0, sizeof(Double) * BLK * BLK);

			Mag_Focus_TMP = img->Magnitude + ((Blk_Row * BLK) * img->info.Ori_stride + (Blk_COl * BLK));
			Pha_Focus_TMP = img->Phase     + ((Blk_Row * BLK) * img->info.Ori_stride + (Blk_COl * BLK));
			for (int k = 0; k < BLK; k++)
				for (int l = 0; l < BLK; l++)
				{
					Mag_TMP = Mag_Focus_TMP + (k * img->info.Ori_stride + l);
					Mag_buf[k * BLK + l] = Mag_TMP[0];

					Pha_TMP = Pha_Focus_TMP + (k * img->info.Ori_stride + l);
					Pha_buf[k * BLK + l] = Pha_TMP[0];
				}

			IDFT_Func(Mag_buf, Pha_buf, BLK, Blk_Row, Blk_COl, img);
		}
	}
	free(Mag_buf);
	free(Pha_buf);
}


void DCT_Process(Img_Buf* img)
{
	Int BLK = Blk_SIZE;

	UChar* Focus_TMP;
	UChar* TMP;
	UChar* Padding_buf;
	Double* DCT_buf;
	Double* DCT_TMP;
	Double* DCT_Focus_TMP;

	img->DCT_img = (Double*)calloc(img->info.width * img->info.height, sizeof(Double));
	img->Rec_DCT_img = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->info.Ori_stride = img->info.width;

	//DCT
	Padding_buf = (UChar*)calloc(BLK * BLK, sizeof(UChar));
	for (Int Blk_Row = 0; Blk_Row < img->info.height / BLK; Blk_Row++)
	{
		for (Int Blk_COl = 0; Blk_COl < img->info.width / BLK; Blk_COl++)
		{
			memset(Padding_buf, 0, sizeof(UChar) * BLK * BLK);

			Focus_TMP = img->Ori_img + ((Blk_Row * BLK) * img->info.Ori_stride + (Blk_COl * BLK));					//왼쪽위
			for (int k = 0; k < BLK; k++)
				for (int l = 0; l < BLK; l++)
				{
					TMP = Focus_TMP + (k * img->info.Ori_stride + l);
					Padding_buf[k * BLK + l] = TMP[0];
				}

			DCT_Func(Padding_buf, BLK, Blk_Row, Blk_COl, img);
		}
	}
	free(Padding_buf);

	//IDCT

	DCT_buf = (Double*)calloc(BLK * BLK, sizeof(Double));
	for (Int Blk_Row = 0; Blk_Row < img->info.height / BLK; Blk_Row++)
	{
		for (Int Blk_COl = 0; Blk_COl < img->info.width / BLK; Blk_COl++)
		{
			memset(DCT_buf, 0, sizeof(Double) * BLK * BLK);

			DCT_Focus_TMP = img->DCT_img + ((Blk_Row * BLK) * img->info.Ori_stride + (Blk_COl * BLK));					//왼쪽위
			for (int k = 0; k < BLK; k++)
				for (int l = 0; l < BLK; l++)
				{
					DCT_TMP = DCT_Focus_TMP + (k * img->info.Ori_stride + l);
					DCT_buf[k * BLK + l] = DCT_TMP[0];
				}

			IDCT_Func(DCT_buf, BLK, Blk_Row, Blk_COl, img);
		}
	}
	free(DCT_buf);
}


void DCT_Func(UChar* buf, Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img)
{
	Double* DCT;
	DCT = (Double*)calloc(BLK * BLK, sizeof(Double));

	Double temp, c_v, c_u;
	int u, v, x, y;

	for (v = 0; v < BLK; v++) {
		if (v == 0) {
			c_v = sqrt(0.5);
		}
		else {
			c_v = 1.0;
		}
		for (u = 0; u < BLK; u++) {
			if (u == 0) {
				c_u = sqrt(0.5);
			}
			else {
				c_u = 1.0;
			}
			temp = 0;

			for (y = 0; y < BLK; y++) {
				for (x = 0; x < BLK; x++) {
					temp += (double)buf[BLK * y + x] * cos((double)(2.0 * x + 1.0) * (double)u * PI / (double)(2.0 * BLK)) * cos((double)(2.0 * y + 1.0) * (double)v * PI / (double)(2.0 * BLK));
				}
			}
			DCT[BLK * v + u] = temp * c_v * c_u * 2.0 / sqrt(BLK * BLK);
		}
	}

	for (Int i = 0; i < BLK; i++)
	{
		for (Int j = 0; j < BLK; j++)
		{
			img->DCT_img[(Blk_Row * BLK + i) * img->info.Ori_stride + (Blk_COl * BLK + j)] = DCT[BLK * i + j];
		}
	}

	FILE* fp;
	fopen_s(&fp, "DCT_Spectrum.raw", "wb");
	if (BLK == img->info.width && BLK == img->info.height)
		fwrite(DCT, sizeof(Double), BLK * BLK, fp);

	fclose(fp);

	free(DCT);
}

void IDCT_Func(Double* buf, Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img)
{
	UChar* IDCT;
	IDCT = (UChar*)calloc(BLK * BLK, sizeof(UChar));
	Double temp, c_v, c_u;
	int u, v, x, y;

	for (y = 0; y < BLK; y++) {
		for (x = 0; x < BLK; x++) {
			temp = 0;
			for (v = 0; v < BLK; v++) {
				if (v == 0) {
					c_v = sqrt(0.5);
				}
				else {
					c_v = 1.0;
				}
				for (u = 0; u < BLK; u++) {
					if (u == 0) {
						c_u = sqrt(0.5);
					}
					else {
						c_u = 1.0;
					}
					temp += (2.0 * c_v * c_u / sqrt(BLK * BLK) * buf[BLK * v + u] * cos((double)(2.0 * x + 1.0) * (double)u * PI / (double)(2.0 * BLK)) * cos((double)(2.0 * y + 1.0) * (double)v * PI / (double)(2.0 * BLK)));
				}
			}

			if (temp < 0)
				temp = (int)(temp - 0.5);

			else
				temp = (int)(temp + 0.5);

			img->Rec_DCT_img[(Blk_Row * BLK + y) * img->info.Ori_stride + (Blk_COl * BLK + x)] = CLIP(temp);

		}
	}

	free(IDCT);
}