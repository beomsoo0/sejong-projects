#include "FILTER.h"

void ARITHMETIC_OPERATION(Img_Buf* img)									
{
	for (int i = 0; i < img->info.width * img->info.height; i++)
	{
		//alpha
		if (img->Ori_img[i] + alpha > 255) {																						// +alpha 255 Cliping
			img->Arith_Addition[i] = 255;
		}
		else if (img->Ori_img[i] + alpha < 0) {																						// +alpha 0 Cliping
			img->Arith_Addition[i] = 0;
		}
		else {																														// +alpha
			img->Arith_Addition[i] = img->Ori_img[i] + alpha;				
		}
		//beta
		if (img->Ori_img[i] - beta > 255) {																							// -beta 255 Cliping
			img->Arith_Subtraction[i] = 255;
		}
		else if (img->Ori_img[i] - beta < 0) {																						// -beta 0 Cliping
			img->Arith_Subtraction[i] = 0;
		}
		else {																														// -beta
			img->Arith_Subtraction[i] = img->Ori_img[i] - beta;				
		}
		//gamma
		if ((double)img->Ori_img[i] * (double)gamma + 0.5 > 255) {																	// *gamma, 반올림 255 Clipping
			img->Arith_Multiplication[i] = 255;
		}
		else if ((double)img->Ori_img[i] * (double)gamma + 0.5 < 0) {																// *gamma, 반올림 0 Clipping
			img->Arith_Multiplication[i] = 0;
		}
		else {																														// *gamma, 반올림
			img->Arith_Multiplication[i] = (double)img->Ori_img[i] * (double)gamma + 0.5;	
		}
		//delta
		if ((double)img->Ori_img[i] / (double)delta + 0.5 > 255) {																	// /delta, 반올림 255 Clipping
			img->Arith_Division[i] = 255;
		}
		else if ((double)img->Ori_img[i] / (double)delta + 0.5 < 0) {																// /delta, 반올림 0 Clipping
			img->Arith_Division[i] = 0;
		}
		else {																														// /delta, 반올림
			img->Arith_Division[i] = (double)img->Ori_img[i] / (double)delta + 0.5;
		}	
	}
}

void HISTOGRAM_MODIFICATION(UChar* Data, int Wid, int Hei, char String[])
{
	int    LUT[Pix_Range] = { 0 };
	int    EQUAL_LUT[Pix_Range] = { 0 };
	int    Accum_Sum[Pix_Range] = { 0 }; 
	
	UChar* EQUAL_IMG = (UChar*)calloc((Wid * Hei), sizeof(UChar));

	char Name_IMG[50] = "Img";
	char Name_Equal[30] = "Equal_";
	char Name_extension[10] = ".raw";

	FILE* wp;

	for (int i = 0; i < Wid * Hei; i++)																														// 화소 개수 Count
		LUT[Data[i]]++;																				

	/////////////////////////////////////////////////////////////////
	//Histogram Equalization
	Accum_Sum[0] = LUT[0];
	for (int i = 1; i < Pix_Range; i++)																														// 누적합 계산 (최대값 = 화소의 총 개수)
		Accum_Sum[i] = Accum_Sum[i - 1] + LUT[i];

	for (int i = 0; i < Pix_Range; i++)																														// Nomalization
		EQUAL_LUT[i] = ((double)Max_Pix / ((double)Wid * (double)Hei)) * (double)Accum_Sum[i] + 0.5;			

	for (int i = 0; i < Wid * Hei; i++)																														//Equalization 진행
		EQUAL_IMG[i] = EQUAL_LUT[Data[i]];

	strcat(Name_Equal, String);
	HISTOGRAM(EQUAL_IMG, Wid, Hei, Name_Equal);

	strcat(Name_Equal, Name_IMG);
	strcat(Name_Equal, Name_extension);
	fopen_s(&wp, Name_Equal, "wb");
	fwrite(EQUAL_IMG, sizeof(UChar), (Wid * Hei), wp);
	fclose(wp);

	/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	//Histogram Specification

	int    LUT_BUF[Pix_Range] = { 0 };
	int    Speci_Accum_Sum[Pix_Range] = { 0 }; //누적 빈도수
	int    SPECI_LUT[Pix_Range] = { 0 };
	int    INV_EQUAL_LUT[Pix_Range] = { 0 };
	char Name_Speci[30] = "Speci_";


	UChar* SPECI_IMG = (UChar*)calloc((Wid * Hei), sizeof(UChar));
																																					
	for (int i = Pix_Range / 2; i < Pix_Range; i++)																											//Specification에 이용할 원하는 Histogram 생성 시작
		LUT_BUF[i] = 2048;																							

	Speci_Accum_Sum[0] = LUT_BUF[0];
	for (int i = 1; i < Pix_Range; i++)																														//누적합
		Speci_Accum_Sum[i] = Speci_Accum_Sum[i - 1] + LUT_BUF[i];

	for (int i = 0; i < Pix_Range; i++)																														//원하는 히스토그램 평활화
		INV_EQUAL_LUT[i] = ((double)Max_Pix / ((double)Wid * (double)Hei)) * (double)Speci_Accum_Sum[i] + 0.5;		

	int Val1, Val2;
	for (int i = 0; i < Pix_Range - 1; i++)																													//역평활화 수행
	{
		Val1 = INV_EQUAL_LUT[i];
		Val2 = INV_EQUAL_LUT[i + 1];
		if (Val1 != Val2)
		{
			for (int j = Val1; j < Val2; j++)
				SPECI_LUT[j] = i + 1;
		}
		else
			SPECI_LUT[Val1] = 0;

	}
	SPECI_LUT[Pix_Range - 1] = Max_Pix;

	for (int i = 0; i < Wid * Hei; i++)																														//Equalization 이후 Specification 진행
		SPECI_IMG[i] = SPECI_LUT[EQUAL_IMG[i]];

	strcat(Name_Speci, String);
	HISTOGRAM(SPECI_IMG, Wid, Hei, Name_Speci);

	strcat(Name_Speci, Name_IMG);
	strcat(Name_Speci, Name_extension);

	fopen_s(&wp, Name_Speci, "wb");
	fwrite(SPECI_IMG, sizeof(UChar), (Wid * Hei), wp);
	fclose(wp);


	/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	//Histogram Stretch


	int Low_pt = 0;																																	// Low, High 좌표 선언
	int High_pt = Max_Pix;
	int Low_th = 10;																																// Low, High 비율 정의
	int High_th = 30;

	char Name_Stret[30] = "Stret_";
	UChar* STERT_IMG = (UChar*)calloc((Wid * Hei), sizeof(UChar));																					// STERT_IMG 메모리 할당



	for (int i = 0; i < Pix_Range; i++) {																											//Low 좌표 생성
		if (Accum_Sum[i] < (double)Wid * (double)Hei * (double)Low_th / (double)100) {
			Low_pt = i;
		}
	}
	for (int i = Pix_Range - 1; i >= 0 ; i--) {																										//High 좌표 생성
		if (Accum_Sum[i] > (double)Wid * (double)Hei * (double)(100 - High_th) / (double)100) {
			High_pt = i;
		}
	}

	for (int i = 0; i < Hei * Wid; i++) {
		if (Data[i] <= Low_pt) {																													//Low 이하 0
			STERT_IMG[i] = 0;
		}
		else if (Data[i] >= High_pt) {																												//High 이상 Max_Pix
			STERT_IMG[i] = Max_Pix;
		}
		else  {
			STERT_IMG[i] =  (double)Max_Pix * ( (double)(Data[i] - Low_pt) / (double)(High_pt - Low_pt) ) + 0.5;									//균일하게 곱함
		}
	}

	strcat(Name_Stret, String);
	HISTOGRAM(STERT_IMG, Wid, Hei, Name_Stret);

	strcat(Name_Stret, Name_IMG);
	strcat(Name_Stret, Name_extension);
	fopen_s(&wp, Name_Stret, "wb");
	fwrite(STERT_IMG, sizeof(UChar), (Wid * Hei), wp);
	fclose(wp);



	/////////////////////////////////////////////////////////////////

	free(EQUAL_IMG);
	free(SPECI_IMG);
	free(STERT_IMG);
}

void HISTOGRAM(UChar* Data, int Wid, int Hei, char String[])
{
	FILE* fp;

	int    LUT      [Pix_Range] = { 0 };
	double Normal_LUT[Pix_Range] = { 0 };
	UChar Output[Pix_Range][Pix_Range] = { 0 };

	char Name_Hist[50] = "Hist_";
	char Name_extension[10] = ".raw";

	int max_cnt = 0;

	for (int i = 0; i < Wid * Hei; i++) 
		LUT[Data[i]]++;

	for (int i = 0; i < Pix_Range; i++)
		max_cnt = max_cnt < LUT[i] ? LUT[i] : max_cnt;

	for (int i = 0; i < Pix_Range; i++)
		Normal_LUT[i] = (double)LUT[i] / (double)max_cnt * 255.0;

	for (int i = 0; i < Pix_Range; i++)
	{
		for (int j = Max_Pix; j > Max_Pix - Normal_LUT[i]; j--)
		{
			Output[j][i] = 255;
		}
	}

	strcat(Name_Hist, String);
	strcat(Name_Hist, Name_extension);

	fopen_s(&fp, Name_Hist, "wb");
	fwrite(Output, sizeof(UChar), Pix_Range * Pix_Range, fp);
	fclose(fp);
}

void IMAGE_FILTERING(Img_Buf* img)
{
	char String[5][10] = { "Ori", "Add" , "Sub" ,"Mul" ,"Div" };

	ARITHMETIC_OPERATION(img);


	HISTOGRAM(img->Ori_img             , img->info.width, img->info.height, String[0]);
	HISTOGRAM(img->Arith_Addition      , img->info.width, img->info.height, String[1]);
	HISTOGRAM(img->Arith_Subtraction   , img->info.width, img->info.height, String[2]);
	HISTOGRAM(img->Arith_Multiplication, img->info.width, img->info.height, String[3]);
	HISTOGRAM(img->Arith_Division      , img->info.width, img->info.height, String[4]);

	HISTOGRAM_MODIFICATION(img->Ori_img, img->info.width, img->info.height, String[0]);
}


