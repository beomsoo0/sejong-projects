#include "main.h"

void Image_Padding(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size);
void Image_Padding_0(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size);
void Image_Padding_half(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size);
UChar Embossing(UChar* buf, int Mask_size);
UChar Median(UChar* buf, int Mask_size);
UChar Homogeneity(UChar* buf, int Mask_size);
UChar Blurring(UChar* buf, int Mask_size);
UChar Derivative_1(UChar* buf, int Mask_size);
UChar Derivative_2(UChar* buf, int Mask_size);
UChar Sharpning(UChar* buf, int Mask_size);
UChar LoG(UChar* buf, int Mask_size);