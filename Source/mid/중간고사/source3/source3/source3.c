#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			SPush(&stack, tok - '0');     // 숫자로 변환하여 PUSH!
		}
		else
		{
			op2 = SPop(&stack);     // 먼저 꺼낸 값이 두 번째 피연산자!
			op1 = SPop(&stack);

			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);
}

int main(void) {

	int N;
	int num[101];
	double sum;
	char input[101];
	scanf("%d", &N);
	scanf("%s", input);
	int i = 0;
	int j = 0;
	while (i < N)
	{
		scanf("%d", &num[i]);
		while (!(('A' <= input[j]) && (input[j] <= 'Z')))
			++j;
		input[j] = num[i] + '0';
		++j;
		++i;
	}
	sum = EvalRPNExp(input);
	printf("%.2lf", sum);
	return (0);
}