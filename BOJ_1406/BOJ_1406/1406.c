#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define STACK_LEN	600000

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

int main(void)
{
	char input[100000];
	char command, alpha;
	int N, len, i;
	Stack L_stack, R_stack;

	scanf("%s", input);
	len = strlen(input);

	StackInit(&L_stack);
	StackInit(&R_stack);

	i = 0;
	while (i < len)
		SPush(&L_stack, input[i++]);

	scanf("%d", &N);
	while (N--)
	{
		scanf(" %c", &command);
		if (!SIsEmpty(&L_stack) && command == 'L')
		{
			SPush(&R_stack, L_stack.stackArr[L_stack.topIndex]);
			SPop(&L_stack);
		}
		else if (!SIsEmpty(&R_stack) && command == 'D')
		{
			SPush(&L_stack, R_stack.stackArr[R_stack.topIndex]);
			SPop(&R_stack);
		}
		else if (!SIsEmpty(&L_stack) && command == 'B')
		{
			SPop(&L_stack);
		}
		else if (command == 'P')
		{
			scanf(" %c", &alpha);
			SPush(&L_stack, alpha);
		}
	}
	while (!SIsEmpty(&L_stack))
	{
		SPush(&R_stack, L_stack.stackArr[L_stack.topIndex]);
		SPop(&L_stack);
	}
	while (!SIsEmpty(&R_stack))
	{
		printf("%c", R_stack.stackArr[R_stack.topIndex]);
		SPop(&R_stack);
	}
	return (0);
}