#include "main.h"

typedef struct _FILE_INFO
{
	FILE* Input_Ori_img; // ���� ������ �ҷ����� ���� ���� ���� ����

	FILE* Output_Add_img;
	FILE* Output_Sub_img;
	FILE* Output_Mul_img;
	FILE* Output_Div_img;
}File_Info;



void INPUT_FILE           (Img_Buf* img/*, File_Info* file*/);
void OUTPUT_FILE          (Img_Buf* img/*, File_Info* file*/);
void IMAGE_INITIALIZATION (Img_Buf* img, File_Info* file);
void IMAGE_SAVE           (Img_Buf* img, File_Info* file);

