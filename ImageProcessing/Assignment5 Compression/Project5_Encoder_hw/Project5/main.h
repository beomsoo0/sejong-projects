#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH      512             // ������ ���� ũ��
#define HEIGHT     512             // ������ ���� ũ��

#define Blk_SIZE     8             // N x N ���

#define Pix_Range  256             // ��� ���� ����

#define Max_Pix    255
#define Min_Pix    0

#define PI			  3.141592653589793238462643383279


#define CLIP(x) (x < Min_Pix) ? Min_Pix : x > Max_Pix ? Max_Pix : x
typedef       char                Char;
typedef       unsigned char       UChar;
typedef       short               Short;
typedef       unsigned short      UShort;
typedef       int                 Int;
typedef       unsigned int        UInt;
typedef       double              Double;
typedef       float               Float;

typedef struct _Image_information
{
	Int width;
	Int height;
	Int Ori_stride;

	Int P_Wid; //�е� ���� ����
	Int P_Hei; //�е� ���� ����
	Int P_stride; //�е� ��Ʈ���̵�

	Int Best_Mode;
}Img_Info;

typedef struct _Image_Buffer
{
	UChar* Ori_img; //���� ���� ������ ���� ���� ����
	UChar* Rec_img; //���� ���� ����

	UChar* Pad_Ori_img;
	UChar* Pad_Rec_img;

	Int* Resi_blk;
	Int* Quant_blk;
	Double* DCT_blk;

	Int Huff_codes[16];
	Int Huff_freq[16];
	Int Huff_ch[16];
	Int Huff_length[16];
	Int Huff_Size;

	Img_Info info;
}Img_Buf;

void IMAGE_Load_or_Save(Img_Buf* img, Int FLAG);
void Encoder(Img_Buf* img);
void Padding_Func(Img_Buf* img);

