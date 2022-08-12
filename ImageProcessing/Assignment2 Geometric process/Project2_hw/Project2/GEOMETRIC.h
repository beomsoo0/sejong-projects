#include "main.h"

#define CLIP(x) (x < Min_Pix) ? Min_Pix : x > Max_Pix ? Max_Pix : x
#define CLIP_HOR(x) (x < WIDTH)  ? x : WIDTH  - 1
#define CLIP_VER(x) (x < HEIGHT) ? x : HEIGHT - 1
#define CLIP_MINUS(x) (x > 0) ? x : 0

void Scaling(Img_Buf* img, int New_Wid, int New_Hei, double Scaling_Val);
void Rotation(Img_Buf* img);

void Image_Padding(Img_Buf* img, UChar* Buf, int width, int height, int Mask_size);

UChar NearesetNeighbor(UChar* Data, double Src_X, double Src_Y, int Stride);
UChar Bilinear        (UChar* Data, double Src_X, double Src_Y, int Stride);
