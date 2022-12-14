#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH      512             // 영상의 가로 크기
#define HEIGHT     512             // 영상의 세로 크기

#define Blk_SIZE     8             // N x N 블록 512x512, 8x8 조절

#define Pix_Range  256             // 흑백 영상 범위

#define Max_Pix    255
#define Min_Pix    0

#define PI			  3.141592653589793238462643383279

#define FilterFlag 'y'

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
}Img_Info;

typedef struct _Image_Buffer
{
	UChar* Ori_img; //원본 영상 저장을 위한 변수 선언
	UChar* Rec_img; //복원 영상 저장

	Double* Real_img; //
	Double* Imag_img; //

	Double* Magnitude;
	Double* Phase;

	Double* DCT_img;
	UChar* Rec_DCT_img;
	Img_Info info;
}Img_Buf;

void IMAGE_Load_or_Save(Img_Buf* img, Int FLAG);
void DFT_Process(Img_Buf* img);
void DCT_Process(Img_Buf* img);
void PSNR(Img_Buf* img);
void PSNR_DCT(Img_Buf* img);


