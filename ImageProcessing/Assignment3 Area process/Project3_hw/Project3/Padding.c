#include "Filtering.h"

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

void Image_Padding_0(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size)
{
	int line, i, j;

	img->padding = (UChar*)calloc((width + Mask_size - 1) * (height + Mask_size - 1), sizeof(UChar));
	for (line = 0; line < (Mask_size / 2); line++)
	{
		//���ϴ� �е�
		for (i = 0; i < width; i++)
		{
			img->padding[(width + Mask_size - 1) * line + Mask_size / 2 + i] = 0;
			img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - line) + Mask_size / 2 + i] = 0;
		}

		//�¿��� �е�
		for (i = 0; i < height; i++)
		{
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + i) + line] = 0;
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + 1 + i) - 1 - line] = 0;
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
						img->padding[(width + Mask_size - 1) * i + j] = 0;
					}
					/*** ���� �е� ***/
					else if (line == 1)
					{
						img->padding[(width + Mask_size - 1) * i + Mask_size / 2 + width + j] = 0;
					}
					/*** ���ϴ� �е� ***/
					else if (line == 2)
					{
						img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + j] = 0;
					}
					/*** ���ϴ� �е� ***/
					else
					{
						img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + Mask_size / 2 + width + j] = 0;
					}
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

void Image_Padding_half(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size)
{
	int line, i, j;

	img->padding = (UChar*)calloc((width + Mask_size - 1) * (height + Mask_size - 1), sizeof(UChar));
	for (line = 0; line < (Mask_size / 2); line++)
	{
		//���ϴ� �е�
		for (i = 0; i < width; i++)
		{
			img->padding[(width + Mask_size - 1) * line + Mask_size / 2 + i] = 128;
			img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - line) + Mask_size / 2 + i] = 128;
		}

		//�¿��� �е�
		for (i = 0; i < height; i++)
		{
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + i) + line] = 128;
			img->padding[(width + Mask_size - 1) * (Mask_size / 2 + 1 + i) - 1 - line] = 128;
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
						img->padding[(width + Mask_size - 1) * i + j] = 128;
					}
					/*** ���� �е� ***/
					else if (line == 1)
					{
						img->padding[(width + Mask_size - 1) * i + Mask_size / 2 + width + j] = 128;
					}
					/*** ���ϴ� �е� ***/
					else if (line == 2)
					{
						img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + j] = 128;
					}
					/*** ���ϴ� �е� ***/
					else
					{
						img->padding[(width + Mask_size - 1) * (height + Mask_size - 2 - i) + Mask_size / 2 + width + j] = 128;
					}
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