#include "Filtering.h"

UChar Embossing(UChar* buf, int Mask_size)
{
	int Mask_Coeff[] = { -1, 0, 0, 0, 0, 0, 0, 0, 1 };
	int Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++) Convolution_All_coeff += (Mask_Coeff[i] * (int)*(buf + i));

	Convolution_All_coeff = Convolution_All_coeff < 0 ? Min_Pix : Convolution_All_coeff;

	return (UChar)Convolution_All_coeff = Convolution_All_coeff + 128 > Max_Pix ? Max_Pix : Convolution_All_coeff + 128;
}

UChar Median(UChar* buf, int Mask_size)
{
	UChar* Asc_buf;
	Asc_buf = (UChar*)calloc(Mask_size * Mask_size, sizeof(UChar));
	int i, j = 0;
	UChar temp;

	for (i = 0; i < Mask_size * Mask_size; i++) {
		*(Asc_buf + i) = *(buf + i);
	}

	for (i = 0; i < Mask_size * Mask_size - 1; i++) {
		for (j = 0; j < Mask_size * Mask_size - 1 - i; j++) {
			if (*(Asc_buf + j) > *(Asc_buf + j + 1)) {
				temp = *(Asc_buf + j);
				*(Asc_buf + j) = *(Asc_buf + j + 1);
				*(Asc_buf + j + 1) = temp;
			}
		}
	}
	return *(Asc_buf + Mask_size * Mask_size / 2);
}

UChar Homogeneity(UChar* buf, int Mask_size)
{
	UChar* temp;
	UChar max;
	temp = (UChar*)calloc(Mask_size * Mask_size, sizeof(UChar));
	
	for (int i = 0; i < Mask_size * Mask_size; i++) {
		*(temp + i) = abs(*(buf + i) - *(buf + Mask_size * Mask_size / 2 - 1));

	}
	max = *(temp);
	for (int i = 0; i < Mask_size * Mask_size; i++) {
		if (*(temp + i) > max) {
			max = *(temp + i);
		}
	}

	return (UChar)max = max + 60 > Max_Pix ? Max_Pix : max + 60;
}

UChar Blurring(UChar* buf, int Mask_size)
{
	double Mask_Coeff[] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };
	double Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++)
		Convolution_All_coeff += (Mask_Coeff[i] * (double)*(buf + i));

	return Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff < Min_Pix ? Min_Pix : Convolution_All_coeff;
}

UChar Derivative_1(UChar* buf, int Mask_size)
{
	int Mask_Sobel_Row[] = { 1, 0, -1, 2, 0, -2, 1, 0, -1};
	int Mask_Sobel_Col[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1};
	int Convolution_Row_coeff = 0;
	int Convolution_Col_coeff = 0;
	int Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++) {
		Convolution_Row_coeff += (Mask_Sobel_Row[i] * (int) *(buf + i));
		Convolution_Col_coeff += (Mask_Sobel_Col[i] * (int) *(buf + i));
	}

	Convolution_Row_coeff = Convolution_Row_coeff > Max_Pix ? Max_Pix : Convolution_Row_coeff < Min_Pix ? Min_Pix : Convolution_Row_coeff;
	Convolution_Col_coeff = Convolution_Col_coeff > Max_Pix ? Max_Pix : Convolution_Col_coeff < Min_Pix ? Min_Pix : Convolution_Col_coeff;
	Convolution_All_coeff = Convolution_Row_coeff + Convolution_Col_coeff;

	return (UChar)Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff;
}

UChar Derivative_2(UChar* buf, int Mask_size)
{
	int Mask_DoG[] = { 0, 0, -1, -1, -1, 0, 0,
							 0, -2, -3, -3, -3, -2, 0,
						   	-1, -3, 5, 5, 5, -3, -1,
						 	-1, -3, 5, 16, 5, -3, -1,
						 	-1, -3, 5, 5, 5, -3, -1,
						 	0, -2, -3, -3, -3, -2, 0,
							0, 0, -1, -1, -1, 0, 0 };
	int Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++) {
		Convolution_All_coeff += (Mask_DoG[i] * (int)*(buf + i));
	}

	return (UChar)Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff < Min_Pix ? Min_Pix : Convolution_All_coeff;
}

UChar LoG(UChar* buf, int Mask_size)
{
	int Mask_DoG[] = { 0, 0, -1, 0, 0,
							0, -1, -2, -1, 0,
							-1, -2, 16, -2, -1,
							0, -1, -2, -1, 0,
							0, 0, -1, 0, 0 };
	
	int Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++) {
		Convolution_All_coeff += (Mask_DoG[i] * (int) * (buf + i));
	}

	return (UChar)Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff < Min_Pix ? Min_Pix : Convolution_All_coeff;
}

UChar Sharpning(UChar* buf, int Mask_size)
{
	int Mask_Coeff[] = { 1, -2, 1, -2, 5, -2, 1, -2, 1 };
	int Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++) {
		Convolution_All_coeff += (Mask_Coeff[i] * (int) * (buf + i));
	}

	return (UChar)Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff < Min_Pix ? Min_Pix : Convolution_All_coeff;
}





void Image_Filtering(Img_Buf* img)
{
	int Mask_size = 3;																					 //MxM size
	int Add_size = Mask_size - 1;																		//더 필요한 size
	UChar* Padding_buf;
	Padding_buf = (UChar*)calloc(Mask_size * Mask_size, sizeof(UChar));
	UChar* Focus_TMP;
	UChar* TMP;
	int Blur_count = 10;																						//Blurring 횟수

	img->Embossing = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Median = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Homogeneity = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Blurring = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Derivative_1 = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Derivative_2 = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Sharpning = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->LoG = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->info.Ori_stride = img->info.width;
	img->info.Padding_stride = img->info.width + Add_size;
	
	//Image_Padding(img, img->Ori_img, img->info.width, img->info.height,  Mask_size);					//Mirroiring
	//Image_Padding_0(img, img->Ori_img, img->info.width, img->info.height, Mask_size);					//zero padding
	Image_Padding_half(img, img->Ori_img, img->info.width, img->info.height, Mask_size);

	for (int i = 0; i < img->info.height; i++)
	{
		for (int j = 0; j < img->info.width; j++)														//이미지 크기 for문
		{
			Focus_TMP = img->padding + (i * img->info.Padding_stride + j);								//Focus_TMP = 3x3 떼어올때 왼쪽 위 좌표
			for (int k = 0; k < Mask_size; k++)															//패딩크기 for문
				for (int l = 0; l < Mask_size; l++)
				{
					TMP = Focus_TMP + (k * img->info.Padding_stride + l);
					*(Padding_buf + k * Mask_size + l) = TMP[0];											//버퍼에 화소값들 넣어줌
				}
			//TEST
			img->Sharpning[i * img->info.Ori_stride + j] = Sharpning(Padding_buf, Mask_size);
			img->Median[i * img->info.Ori_stride + j] = Median(Padding_buf, Mask_size);
			img->LoG[i * img->info.Ori_stride + j] = LoG(Padding_buf, Mask_size);									//마스크사이즈 조절
			
		}
	}
	
	Image_Padding_half(img, img->Median, img->info.width, img->info.height, Mask_size);

	for (int i = 0; i < img->info.height; i++)
	{
		for (int j = 0; j < img->info.width; j++)														//이미지 크기 for문
		{
			Focus_TMP = img->padding + (i * img->info.Padding_stride + j);								//Focus_TMP = 3x3 떼어올때 왼쪽 위 좌표
			for (int k = 0; k < Mask_size; k++)															//패딩크기 for문
				for (int l = 0; l < Mask_size; l++)
				{
					TMP = Focus_TMP + (k * img->info.Padding_stride + l);
					*(Padding_buf + k * Mask_size + l) = TMP[0];											//버퍼에 화소값들 넣어줌
				}
			//TEST
			img->Homogeneity[i * img->info.Ori_stride + j] = Homogeneity(Padding_buf, Mask_size);
		}
	}



	free(img->padding);
}