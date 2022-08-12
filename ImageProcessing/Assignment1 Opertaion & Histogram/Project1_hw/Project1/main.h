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
}Img_Info;

typedef struct _Image_Buffer
{
	UChar* Ori_img; //���� ���� ������ ���� ���� ����

	UChar* Arith_Addition;
	UChar* Arith_Subtraction;
	UChar* Arith_Multiplication;
	UChar* Arith_Division;

	Img_Info info;
}Img_Buf;


void FILE_Load_or_Save(Img_Buf* img, int FLAG);
void IMAGE_FILTERING  (Img_Buf* img          );

