#include "main.h"

typedef struct _FILE_INFO
{
	FILE* Input_Ori_img; // ���� ������ �ҷ����� ���� ���� ���� ����

}File_Info;

void INPUT_FILE(Img_Buf* img);
void OUTPUT_FILE(Img_Buf* img);

void IMAGE_INITIALIZATION(Img_Buf* img, File_Info* file);


