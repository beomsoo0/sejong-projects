#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH      512              // ������ ���� ũ��
#define HEIGHT     512             // ������ ���� ũ��

#define Pix_Range  256          // ��� ���� ����

#define Max_Pix    255
#define Min_Pix    0

typedef unsigned char UChar;

typedef struct _Image_information
{
	int width;
	int height;
	int Ori_stride;																			// org stride
	int Padding_stride;																		//padding �� stride
}Img_Info;

typedef struct _Image_Buffer
{
	UChar* Ori_img; //���� ���� ������ ���� ���� ����
	
	UChar* padding; // �е� ���� ���� ����

	UChar* Embossing;
	UChar* Median;
	UChar* Homogeneity;
	UChar* Blurring;
	UChar* Derivative_1;
	UChar* Derivative_2;
	UChar* Sharpning;
	UChar* LoG;

	Img_Info info;
}Img_Buf;

void IMAGE_Load_or_Save(Img_Buf* img, int FLAG);
void Image_Filtering(Img_Buf* img);


