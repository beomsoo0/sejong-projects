#include "GEOMETRIC.h"
#include "math.h"

UChar NearesetNeighbor(UChar *Data, double Src_X, double Src_Y, int Stride)
{
	return Data[((int)(Src_Y + 0.5) * Stride + (int)(Src_X + 0.5))];								//(int) ���� ����ȯ  stride 1���� �迭�̶� ���
}

UChar Bilinear(UChar* Data, double Src_X, double Src_Y, int Stride)
{
	int Src_X_Plus_1, Src_Y_Plus_1;
	double Hor_Wei, Ver_Wei; //Horizontal Weight, Vertical Weight
	int TL, TR, BL, BR; //�� ȭ�� ��ġ

	Src_X_Plus_1 = CLIP_HOR((int)Src_X + 1);
	Src_Y_Plus_1 = CLIP_VER((int)Src_Y + 1);

	Hor_Wei = Src_X - (int)Src_X;
	Ver_Wei = Src_Y - (int)Src_Y;

	TL = (int)Src_Y   * Stride + (int)Src_X;         //top left ��ǥ
	TR = (int)Src_Y   * Stride + Src_X_Plus_1;
	BL = Src_Y_Plus_1 * Stride + (int)Src_X;
	BR = Src_Y_Plus_1 * Stride + Src_X_Plus_1;

	UChar TMP =
	(1 - Ver_Wei)*  (((1 - Hor_Wei) * Data[TL]) + (Hor_Wei * Data[TR])) +

		 Ver_Wei *  (((1 - Hor_Wei) * Data[BL]) + (Hor_Wei * Data[BR])) + 0.5;

	return TMP;
}

UChar Cubic(UChar* Data, double Src_X, double Src_Y, int Stride)
{
	int Src_X_Minus_1, Src_X_Plus_1, Src_X_Plus_2, Src_Y_Minus_1, Src_Y_Plus_1, Src_Y_Plus_2;
	double Hor_Wei, Ver_Wei; //Horizontal Weight, Vertical Weight
	double a = 0.5;
	Src_X_Minus_1 = CLIP_MINUS((int)Src_X - 1);												//��ǥ
	Src_X_Plus_1 = CLIP_HOR((int)Src_X + 1);
	Src_X_Plus_2 = CLIP_HOR((int)Src_X + 2);
	Src_Y_Minus_1 = CLIP_MINUS((int)Src_Y - 1);
	Src_Y_Plus_1 = CLIP_VER((int)Src_Y + 1);
	Src_Y_Plus_2 = CLIP_VER((int)Src_Y + 2);

	Hor_Wei = Src_X - (int)Src_X;
	Ver_Wei = Src_Y - (int)Src_Y;


	double TMP_Cubic_0 =
		(a * pow(Hor_Wei + 1, 3) - 5 * a * pow(Hor_Wei + 1, 2) + 8 * a * (Hor_Wei + 1) - 4 * a) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Minus_1]
		+ ((a + 2) * pow(Hor_Wei, 3) - (a + 3) * pow(Hor_Wei, 2) + 1) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X]
		+ ((a + 2) * pow(1 - Hor_Wei, 3) - (a + 3) * pow(1 - Hor_Wei, 2) + 1) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Plus_1]
		+ (a * pow(2 - Hor_Wei, 3) - 5 * a * pow(2 - Hor_Wei, 2) + 8 * a * (2 - Hor_Wei) - 4 * a) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Plus_2];

	double TMP_Cubic_1 =
		(a * pow(Hor_Wei + 1, 3) - 5 * a * pow(Hor_Wei + 1, 2) + 8 * a * (Hor_Wei + 1) - 4 * a) * Data[(int)Src_Y * Stride + (int)Src_X_Minus_1]
		+ ((a + 2) * pow(Hor_Wei, 3) - (a + 3) * pow(Hor_Wei, 2) + 1) * Data[(int)Src_Y * Stride + (int)Src_X]
		+ ((a + 2) * pow(1 - Hor_Wei, 3) - (a + 3) * pow(1 - Hor_Wei, 2) + 1) * Data[(int)Src_Y * Stride + (int)Src_X_Plus_1]
		+ (a * pow(2 - Hor_Wei, 3) - 5 * a * pow(2 - Hor_Wei, 2) + 8 * a * (2 - Hor_Wei) - 4 * a) * Data[(int)Src_Y * Stride + (int)Src_X_Plus_2];

	double TMP_Cubic_2 =
		(a * pow(Hor_Wei + 1, 3) - 5 * a * pow(Hor_Wei + 1, 2) + 8 * a * (Hor_Wei + 1) - 4 * a) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Minus_1]
		+ ((a + 2) * pow(Hor_Wei, 3) - (a + 3) * pow(Hor_Wei, 2) + 1) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X]
		+ ((a + 2) * pow(1 - Hor_Wei, 3) - (a + 3) * pow(1 - Hor_Wei, 2) + 1) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Plus_1]
		+ (a * pow(2 - Hor_Wei, 3) - 5 * a * pow(2 - Hor_Wei, 2) + 8 * a * (2 - Hor_Wei) - 4 * a) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Plus_2];

	double TMP_Cubic_3 =
		(a * pow(Hor_Wei + 1, 3) - 5 * a * pow(Hor_Wei + 1, 2) + 8 * a * (Hor_Wei + 1) - 4 * a) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Minus_1]
		+ ((a + 2) * pow(Hor_Wei, 3) - (a + 3) * pow(Hor_Wei, 2) + 1) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X]
		+ ((a + 2) * pow(1 - Hor_Wei, 3) - (a + 3) * pow(1 - Hor_Wei, 2) + 1) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Plus_1]
		+ (a * pow(2 - Hor_Wei, 3) - 5 * a * pow(2 - Hor_Wei, 2) + 8 * a * (2 - Hor_Wei) - 4 * a) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Plus_2];

	UChar TMP =
		(a * pow(Ver_Wei + 1, 3) - 5 * a * pow(Ver_Wei + 1, 2) + 8 * a * (Ver_Wei + 1) - 4 * a) * TMP_Cubic_0
		+ ((a + 2) * pow(Ver_Wei, 3) - (a + 3) * pow(Ver_Wei, 2) + 1) * TMP_Cubic_1
		+ ((a + 2) * pow(1 - Ver_Wei, 3) - (a + 3) * pow(1 - Ver_Wei, 2) + 1) * TMP_Cubic_2
		+ (a * pow(2 - Ver_Wei, 3) - 5 * a * pow(2 - Ver_Wei, 2) + 8 * a * (2 - Ver_Wei) - 4 * a) * TMP_Cubic_3
			+ 0.5;
	UChar TMP_Cubic = CLIP(TMP);
	return TMP_Cubic;
}

UChar Bspline(UChar* Data, double Src_X, double Src_Y, int Stride)
{
	int Src_X_Minus_1, Src_X_Plus_1, Src_X_Plus_2, Src_Y_Minus_1, Src_Y_Plus_1, Src_Y_Plus_2;	
	double Hor_Wei, Ver_Wei; //Horizontal Weight, Vertical Weight
	Src_X_Minus_1 = CLIP_MINUS((int)Src_X - 1);
	Src_X_Plus_1 = CLIP_HOR((int)Src_X + 1);
	Src_X_Plus_2 = CLIP_HOR((int)Src_X + 2);
	Src_Y_Minus_1 = CLIP_MINUS((int)Src_Y - 1);
	Src_Y_Plus_1 = CLIP_VER((int)Src_Y + 1);
	Src_Y_Plus_2 = CLIP_VER((int)Src_Y + 2);
	Hor_Wei = Src_X - (int)Src_X;
	Ver_Wei = Src_Y - (int)Src_Y;
	double TMP_Bspline_0 = 
		((-1.0 / 6.0) * pow(Hor_Wei + 1, 3) + pow(Hor_Wei + 1, 2) - 2 * (Hor_Wei + 1) + (4.0 / 3.0)) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Minus_1]
		+ ((1.0 / 2.0) * pow(Hor_Wei, 3) - pow(Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X]
		+ ((1.0 / 2.0) * pow(1 - Hor_Wei, 3) - pow(1 - Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Plus_1]
		+ ((-1.0 / 6.0) * pow(2 - Hor_Wei, 3) + pow(2 - Hor_Wei, 2) - 2 * (2 - Hor_Wei) + (4.0 / 3.0)) * Data[(int)Src_Y_Minus_1 * Stride + (int)Src_X_Plus_2];

	double TMP_Bspline_1 =
		((-1.0 / 6.0) * pow(Hor_Wei + 1, 3) + pow(Hor_Wei + 1, 2) - 2 * (Hor_Wei + 1) + (4.0 / 3.0)) * Data[(int)Src_Y * Stride + (int)Src_X_Minus_1]
		+ ((1.0 / 2.0) * pow(Hor_Wei, 3) - pow(Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y * Stride + (int)Src_X]
		+ ((1.0 / 2.0) * pow(1 - Hor_Wei, 3) - pow(1 - Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y * Stride + (int)Src_X_Plus_1]
		+ ((-1.0 / 6.0) * pow(2 - Hor_Wei, 3) + pow(2 - Hor_Wei, 2) - 2 * (2 - Hor_Wei) + (4.0 / 3.0)) * Data[(int)Src_Y * Stride + (int)Src_X_Plus_2];

	double TMP_Bspline_2 =
		((-1.0 / 6.0) * pow(Hor_Wei + 1, 3) + pow(Hor_Wei + 1, 2) - 2 * (Hor_Wei + 1) + (4.0 / 3.0)) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Minus_1]
		+ ((1.0 / 2.0) * pow(Hor_Wei, 3) - pow(Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X]
		+ ((1.0 / 2.0) * pow(1 - Hor_Wei, 3) - pow(1 - Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Plus_1]
		+ ((-1.0 / 6.0) * pow(2 - Hor_Wei, 3) + pow(2 - Hor_Wei, 2) - 2 * (2 - Hor_Wei) + (4.0 / 3.0)) * Data[(int)Src_Y_Plus_1 * Stride + (int)Src_X_Plus_2];

	double TMP_Bspline_3 =
		((-1.0 / 6.0) * pow(Hor_Wei + 1, 3) + pow(Hor_Wei + 1, 2) - 2 * (Hor_Wei + 1) + (4.0 / 3.0)) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Minus_1]
		+ ((1.0 / 2.0) * pow(Hor_Wei, 3) - pow(Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X]
		+ ((1.0 / 2.0) * pow(1 - Hor_Wei, 3) - pow(1 - Hor_Wei, 2) + (2.0 / 3.0)) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Plus_1]
		+ ((-1.0 / 6.0) * pow(2 - Hor_Wei, 3) + pow(2 - Hor_Wei, 2) - 2 * (2 - Hor_Wei) + (4.0 / 3.0)) * Data[(int)Src_Y_Plus_2 * Stride + (int)Src_X_Plus_2];

	UChar TMP_Bspline =
		((-1.0 / 6.0) * pow(Ver_Wei + 1, 3) + pow(Ver_Wei + 1, 2) - 2 * (Ver_Wei + 1) + (4.0 / 3.0)) * TMP_Bspline_0
		+ ((1.0 / 2.0) * pow(Ver_Wei, 3) - pow(Ver_Wei, 2) + (2.0 / 3.0)) * TMP_Bspline_1
		+ ((1.0 / 2.0) * pow(1 - Ver_Wei, 3) - pow(1 - Ver_Wei, 2) + (2.0 / 3.0)) * TMP_Bspline_2
		+ ((-1.0 / 6.0) * pow(2 - Ver_Wei, 3) + pow(2 - Ver_Wei, 2) - 2 * (2 - Ver_Wei) + (4.0 / 3.0)) * TMP_Bspline_3
		+ 0.5;
	return TMP_Bspline;
}

void Scaling(Img_Buf* img, int New_Wid, int New_Hei, double Scaling_Val)
{
	double Src_x, Src_y;														//���� ȭ�� ��ġ

	img->Near_Scale = (UChar*)calloc(New_Wid * New_Hei, sizeof(UChar));
	img->Bi_Scale   = (UChar*)calloc(New_Wid * New_Hei, sizeof(UChar));
	img->Cubic_Scale = (UChar*)calloc(New_Wid * New_Hei, sizeof(UChar));
	img->Bspline_Scale = (UChar*)calloc(New_Wid * New_Hei, sizeof(UChar));

	for (int i = 0; i < New_Hei; i++)
	{
		for (int j = 0; j < New_Wid; j++)
		{
			Src_x = (double)j / Scaling_Val;
			Src_y = (double)i / Scaling_Val;

			img->Near_Scale[i * New_Wid + j] = NearesetNeighbor(img->Ori_img, Src_x, Src_y, img->info.width);
			img->Bi_Scale  [i * New_Wid + j] = Bilinear        (img->Ori_img, Src_x, Src_y, img->info.width);
			img->Cubic_Scale[i * New_Wid + j] = Cubic		   (img->Ori_img, Src_x, Src_y, img->info.width);
			img->Bspline_Scale[i * New_Wid + j] = Bspline	   (img->Ori_img, Src_x, Src_y, img->info.width);
		}
	}
}

void Rotation(Img_Buf* img)
{
	FILE *up1, *up2, * up3, * up4;

	double Angle;
	double Basis_X, Basis_Y;	// Source ��ġ  = src

	int New_X, New_Y;
	int Center_X = img->info.width / 2, Center_Y = img->info.height / 2;									//�߽��� ���� ȸ�� �� ���

	fopen_s(&up1, "Img_Near_Ro.raw", "wb");
	fopen_s(&up2, "Img_Bi_Ro.raw", "wb");
	fopen_s(&up3, "Img_Cubic_Ro.raw", "wb");
	fopen_s(&up4, "Img_Bspline_Ro.raw", "wb");

	img->Near_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bi_Ro   = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Cubic_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bspline_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));

	for (Angle = 0; Angle <= 360; Angle += 4)
	{
		double Seta = PI / 180.0 * Angle;

		for (int i = 0; i < img->info.height; i++)  
		{
			for (int j = 0; j < img->info.width; j++)
			{
				Basis_X = (j - Center_X) * cos(Seta) + (i - Center_Y) * sin(Seta) + Center_X;
				Basis_Y = (i - Center_Y) * cos(Seta) - (j - Center_X) * sin(Seta) + Center_Y;

				New_X = (int)Basis_X;
				New_Y = (int)Basis_Y;

				if (!(New_X < 0 || New_X >= img->info.width - 1 || New_Y < 0 || New_Y >= img->info.height - 1)) // ���� ȭ�Ұ� ���� ��� �ۿ� ��ġ ���� ����ϱ�!!  �Ƹ� ȭ�� ��?
				{
					img->Near_Ro[i * img->info.width + j] = NearesetNeighbor(img->Ori_img, Basis_X, Basis_Y, img->info.width);
					img->Bi_Ro[i * img->info.width + j] = Bilinear(img->Ori_img, Basis_X, Basis_Y, img->info.width);
					img->Cubic_Ro[i * img->info.width + j] = Cubic(img->Ori_img, Basis_X, Basis_Y, img->info.width);
					img->Bspline_Ro[i * img->info.width + j] = Bspline(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				}
				else
				{
					img->Near_Ro[i * img->info.width + j] = 0;
					img->Bi_Ro[i * img->info.width + j] = 0;
					img->Cubic_Ro[i * img->info.width + j] = 0;
					img->Bspline_Ro[i * img->info.width + j] = 0;
				}
			}
		}

		fwrite(img->Near_Ro, sizeof(UChar), (img->info.width * img->info.height), up1);
		fwrite(img->Bi_Ro, sizeof(UChar), (img->info.width * img->info.height), up2);
		fwrite(img->Cubic_Ro, sizeof(UChar), (img->info.width * img->info.height), up3);
		fwrite(img->Bspline_Ro, sizeof(UChar), (img->info.width * img->info.height), up4);
	}

	free(img->Near_Ro);
	free(img->Bi_Ro);
	free(img->Cubic_Ro);
	free(img->Bspline_Ro);

	fclose(up1);
	fclose(up2);
	fclose(up3);
	fclose(up4);
}

void Rotation_23_Zero(Img_Buf* img)
{
	FILE* up1, * up2, * up3, * up4;

	
	double Basis_X, Basis_Y;	// Source ��ġ  = src

	int New_X, New_Y;
	
	fopen_s(&up1, "Img_Near_Ro_23_(0,0).raw", "wb");
	fopen_s(&up2, "Img_Bi_Ro_23_(0,0).raw", "wb");
	fopen_s(&up3, "Img_Cubic_Ro_23_(0,0).raw", "wb");
	fopen_s(&up4, "Img_Bspline_Ro_23_(0,0).raw", "wb");

	img->Near_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bi_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Cubic_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bspline_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));

	int Center_X = 0, Center_Y = 0;																			//���� ���� ȸ�� �� ���
	double Angle = 23.0;
	
	double Seta = PI / 180.0 * Angle;
		
	for (int i = 0; i < img->info.height; i++)
	{
		for (int j = 0; j < img->info.width; j++)
		{
			Basis_X = (j - Center_X) * cos(Seta) + (i - Center_Y) * sin(Seta) + Center_X;
			Basis_Y = (i - Center_Y) * cos(Seta) - (j - Center_X) * sin(Seta) + Center_Y;

			New_X = (int)Basis_X;
			New_Y = (int)Basis_Y;

			if (!(New_X < 0 || New_X >= img->info.width - 1 || New_Y < 0 || New_Y >= img->info.height - 1)) // ���� ȭ�Ұ� ���� ��� �ۿ� ��ġ ���� ����ϱ�!!  �Ƹ� ȭ�� ��?
			{
				img->Near_Ro[i * img->info.width + j] = NearesetNeighbor(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Bi_Ro[i * img->info.width + j] = Bilinear(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Cubic_Ro[i * img->info.width + j] = Cubic(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Bspline_Ro[i * img->info.width + j] = Bspline(img->Ori_img, Basis_X, Basis_Y, img->info.width);
			}
			else
			{
				img->Near_Ro[i * img->info.width + j] = 0;
				img->Bi_Ro[i * img->info.width + j] = 0;
				img->Cubic_Ro[i * img->info.width + j] = 0;
				img->Bspline_Ro[i * img->info.width + j] = 0;
			}
		}
	}
		
	fwrite(img->Near_Ro, sizeof(UChar), (img->info.width * img->info.height), up1);
	fwrite(img->Bi_Ro, sizeof(UChar), (img->info.width * img->info.height), up2);
	fwrite(img->Cubic_Ro, sizeof(UChar), (img->info.width * img->info.height), up3);
	fwrite(img->Bspline_Ro, sizeof(UChar), (img->info.width * img->info.height), up4);
	

	free(img->Near_Ro);
	free(img->Bi_Ro);
	free(img->Cubic_Ro);
	free(img->Bspline_Ro);

	fclose(up1);
	fclose(up2);
	fclose(up3);
	fclose(up4);
}

void Rotation_23_Cen(Img_Buf* img)
{
	FILE* up1, * up2, * up3, * up4;


	double Basis_X, Basis_Y;	// Source ��ġ  = src

	int New_X, New_Y;
	
	
	fopen_s(&up1, "Img_Near_Ro_23_Cen.raw", "wb");
	fopen_s(&up2, "Img_Bi_Ro_23_Cen.raw", "wb");
	fopen_s(&up3, "Img_Cubic_Ro_23_Cen.raw", "wb");
	fopen_s(&up4, "Img_Bspline_Ro_23_Cen.raw", "wb");

	img->Near_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bi_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Cubic_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->Bspline_Ro = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));

	double Angle = 23.0;
	int Center_X = img->info.width / 2, Center_Y = img->info.height / 2;									//�߽��� ���� ȸ�� �� ���
	double Seta = PI / 180.0 * Angle;

	for (int i = 0; i < img->info.height; i++)
	{
		for (int j = 0; j < img->info.width; j++)
		{
			Basis_X = (j - Center_X) * cos(Seta) + (i - Center_Y) * sin(Seta) + Center_X;
			Basis_Y = (i - Center_Y) * cos(Seta) - (j - Center_X) * sin(Seta) + Center_Y;

			New_X = (int)Basis_X;
			New_Y = (int)Basis_Y;

			if (!(New_X < 0 || New_X >= img->info.width - 1 || New_Y < 0 || New_Y >= img->info.height - 1)) // ���� ȭ�Ұ� ���� ��� �ۿ� ��ġ ���� ����ϱ�!!  �Ƹ� ȭ�� ��?
			{
				img->Near_Ro[i * img->info.width + j] = NearesetNeighbor(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Bi_Ro[i * img->info.width + j] = Bilinear(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Cubic_Ro[i * img->info.width + j] = Cubic(img->Ori_img, Basis_X, Basis_Y, img->info.width);
				img->Bspline_Ro[i * img->info.width + j] = Bspline(img->Ori_img, Basis_X, Basis_Y, img->info.width);
			}
			else
			{
				img->Near_Ro[i * img->info.width + j] = 0;
				img->Bi_Ro[i * img->info.width + j] = 0;
				img->Cubic_Ro[i * img->info.width + j] = 0;
				img->Bspline_Ro[i * img->info.width + j] = 0;
			}
		}
	}


	fwrite(img->Near_Ro, sizeof(UChar), (img->info.width * img->info.height), up1);
	fwrite(img->Bi_Ro, sizeof(UChar), (img->info.width * img->info.height), up2);
	fwrite(img->Cubic_Ro, sizeof(UChar), (img->info.width * img->info.height), up3);
	fwrite(img->Bspline_Ro, sizeof(UChar), (img->info.width * img->info.height), up4);
	
	free(img->Near_Ro);
	free(img->Bi_Ro);
	free(img->Cubic_Ro);
	free(img->Bspline_Ro);

	fclose(up1);
	fclose(up2);
	fclose(up3);
	fclose(up4);
}



void Image_Padding(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size)
{
	int line, i, j;

	img->padding = (UChar*)calloc((width + Mask_size - 1) * (height + Mask_size - 1), sizeof(UChar));
	for (line = 0; line < (Mask_size / 2); line++)
	{
		//���ϴ� �е�
		for (i = 0; i < width; i++)
		{
			img->padding[(width + Mask_size - 1) * line + Mask_size / 2 + i] = Buf[i];
			img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - line) + Mask_size / 2 + i] = Buf[i + (width * (height - 1))];
		}

		//�¿��� �е�
		for (i = 0; i < height; i++)
		{
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + i) + line] = Buf[i * width];
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + 1 + i) - 1 - line] = Buf[i * width + (width - 1)];
		}
	}

	for (line = 0; line < 4; line++)
	{
		for (i = 0; i < (Mask_size / 2); i++)
		{
			for (j = 0; j < (Mask_size / 2); j++)
			{
				/*** �»�� �е� ***/
				if (line == 0)
				{
					img->padding[(width + Mask_size - 1) * i + j] = Buf[0];
				}
				/*** ���� �е� ***/
				else if (line == 1)
				{
					img->padding[(width + Mask_size - 1) * i + Mask_size / 2 + width + j] = Buf[width - 1];
				}
				/*** ���ϴ� �е� ***/
				else if (line == 2)
				{
					img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + j] = Buf[width * (height - 1)];
				}
				/*** ���ϴ� �е� ***/
				else
				{
					img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + Mask_size / 2 + width + j] = Buf[width * height - 1];
				}
			}
		}
	}

	/*** ���� ���� �ҷ����� ***/
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + i) + Mask_size / 2 + j] = Buf[i * width + j];
		}
	}
}

UChar Blurring(UChar* buf, int Mask_size)
{
	double Mask_Coeff[] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };
	double Convolution_All_coeff = 0;

	for (int i = 0; i < Mask_size * Mask_size; i++)
		Convolution_All_coeff += (Mask_Coeff[i] * (double)buf[i]);

	return Convolution_All_coeff = Convolution_All_coeff > Max_Pix ? Max_Pix : Convolution_All_coeff < Min_Pix ? Min_Pix : Convolution_All_coeff;
}

void Image_Filtering(Img_Buf* img)
{
	int Mask_size = 3;         //MxM size
	int Add_size = Mask_size / 2 + 1;
	UChar Padding_buf[9] = { 0 };

	Image_Padding(img, img->Ori_img, img->info.width, img->info.height, 3);

	img->Result_Blurring = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));

	for (int i = 0; i < img->info.height; i++)
	{
		for (int j = 0; j < img->info.width; j++)
		{
			for (int k = 0; k < Mask_size; k++)
				for (int l = 0; l < Mask_size; l++)
					Padding_buf[k * Mask_size + l] = img->padding[(i + k) * (img->info.width + Add_size) + (j + l)];

			img->Result_Blurring[i * img->info.width + j] = Blurring(&Padding_buf, Mask_size);
		}
	}
	free(img->padding);
}

void Geometric_Trancsformation(Img_Buf* img)
{
	double Scaling_Val = Scale_factor;

	int New_Wid = (double)img->info.width * Scaling_Val + 0.5;											//���� �ٲ� ���μ���
	int New_Hei = (double)img->info.height * Scaling_Val + 0.5;

	if (Scaling_Val < 1) // ���� ��Ҹ� ���� ����
	{
		Image_Filtering(img);  ////////////// ���� 3-2�� (���� ��ҽ� ���) ---> Filtering.c �ڵ�
		memcpy(img->Ori_img, img->Result_Blurring, sizeof(UChar) * img->info.width * img->info.height);
		free(img->Result_Blurring);
	}


	Scaling (img, New_Wid, New_Hei, Scaling_Val);
	//Rotation(img);
	Rotation_23_Zero(img);
	Rotation_23_Cen(img);


	FILE* wp;
	fopen_s(&wp, "Img_Near_Scale.raw", "wb");
	fwrite(img->Near_Scale, sizeof(UChar), (New_Wid * New_Hei), wp);
	free(img->Near_Scale);

	fopen_s(&wp, "Img_Bi_Scale.raw", "wb");
	fwrite(img->Bi_Scale, sizeof(UChar), (New_Wid * New_Hei), wp);
	free(img->Bi_Scale);

	fopen_s(&wp, "Img_Cubic_Scale.raw", "wb");
	fwrite(img->Cubic_Scale, sizeof(UChar), (New_Wid * New_Hei), wp);
	free(img->Cubic_Scale);

	fopen_s(&wp, "Img_Bspline_Scale.raw", "wb");
	fwrite(img->Bspline_Scale, sizeof(UChar), (New_Wid * New_Hei), wp);
	free(img->Bspline_Scale);
	fclose(wp);
}