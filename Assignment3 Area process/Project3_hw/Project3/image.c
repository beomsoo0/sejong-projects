#include "image.h"

void INPUT_FILE(Img_Buf* img)
{
	File_Info file;

	fopen_s(&file.Input_Ori_img, "lena_512x512.raw", "rb");
	//fopen_s(&file.Input_Ori_img, "Lena-scratch-noise.raw", "rb");
	//fopen_s(&file.Input_Ori_img, "Lena-gaussian-noise.raw", "rb");
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
	FILE* wp;
	fopen_s(&wp, "Embossing.raw", "wb");
	fwrite(img->Embossing, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Median.raw", "wb");
	fwrite(img->Median, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Homogeneity.raw", "wb");
	fwrite(img->Homogeneity, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Blurring.raw", "wb");
	fwrite(img->Blurring, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Derivative_1.raw", "wb");
	fwrite(img->Derivative_1, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Derivative_2.raw", "wb");
	fwrite(img->Derivative_2, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "Sharpning.raw", "wb");
	fwrite(img->Sharpning, sizeof(UChar), WIDTH * HEIGHT, wp);
	fopen_s(&wp, "LoG.raw", "wb");
	fwrite(img->LoG, sizeof(UChar), WIDTH * HEIGHT, wp);
	fclose(wp);


	free(img->Ori_img);
	free(img->Embossing);
	free(img->Median);
	free(img->Homogeneity);
	free(img->Blurring);
	free(img->Derivative_1);
	free(img->Derivative_2);
	free(img->Sharpning);
	free(img->LoG);
}



void IMAGE_Load_or_Save(Img_Buf* img, int FLAG)
{
	if (FLAG)
		INPUT_FILE(img);
	else
		OUTPUT_FILE(img);
}
