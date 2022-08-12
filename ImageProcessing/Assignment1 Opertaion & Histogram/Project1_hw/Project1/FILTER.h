#include "main.h"

#define alpha      30  //��� ���� = ���� ���� + alpha 
#define beta       30  //��� ���� = ���� ���� - beta 
#define gamma      1.2 //��� ���� = ���� ���� * gamma 
#define delta      1.2 //��� ���� = ���� ���� / delta 

typedef struct _HISTOGRAM_INFO
{
	UChar* Ori;
	UChar* Sub;
	UChar* Add;
	UChar* Mul;
	UChar* Div;
}Histogram_Info;


void ARITHMETIC_OPERATION(Img_Buf* img);
void HISTOGRAM(UChar* Data, int Wid, int Hei, char String[]);
void HISTOGRAM_MODIFICATION(UChar* Data, int Wid, int Hei, char String[]);