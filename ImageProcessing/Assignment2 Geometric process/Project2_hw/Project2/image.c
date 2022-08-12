#include "image.h"

void INPUT_FILE(Img_Buf* img)															
{
	File_Info file;

	fopen_s(&file.Input_Ori_img, "lena_512x512.raw ", "rb");							//lena ����
	//fopen_s(&file.Input_Ori_img, "city_1280x720.raw ", "rb");							//city ����

	IMAGE_INITIALIZATION(img, &file);

	fclose(file.Input_Ori_img);
}

void IMAGE_INITIALIZATION(Img_Buf* img, File_Info* file)	
{
	img->info.width = WIDTH;
	img->info.height = HEIGHT;
	img->Ori_img = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));

	fread(img->Ori_img, sizeof(UChar), (img->info.width * img->info.height), file->Input_Ori_img);
}


void OUTPUT_FILE(Img_Buf* img)
{
	free(img->Ori_img);
}



void IMAGE_Load_or_Save(Img_Buf* img, int FLAG)
{
	if (FLAG)
		INPUT_FILE(img);
	else
		OUTPUT_FILE(img);
}
