#include "main.h"

typedef enum {
	false = 0,
	true = 1
} _bool;

_bool bool(int num) {
	if (num > 0) return true;
	return false;
}

void main()
{
	Img_Buf image;          

	IMAGE_Load_or_Save(&image, bool(true));

	Geometric_Trancsformation(&image);

	IMAGE_Load_or_Save(&image, bool(false));
}