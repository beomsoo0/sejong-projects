#include <stdio.h>
#include "InfixCalculator.h"

int main(void) {

	int N;
	int num = 0;
	double sum = 0;
	char input[101];
	scanf("%d", &N);
	scanf("%s", input);
	int i = 0;
	int j = 0;
	while (i < N)
	{
		scanf("%d", num);
		while (!('A' <= input[j] && input[j] <= 'Z'))
			++j;
		input[j] = num;
		++i;
	}
	sum = EvalRPNExp(&input[0]);
	printf("%.2lf", sum);
	return (0);
}