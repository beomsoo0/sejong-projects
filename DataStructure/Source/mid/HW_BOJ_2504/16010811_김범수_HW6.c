#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define STACK_LEN	31
#define small -1
#define big -2
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

int		main(void)
{
	Stack stack;
	char input[31];
	int len, i, sum, num;

	scanf("%s", input);
	len = strlen(input);
	StackInit(&stack);

	i = 0;
	while (i < len)
	{
		switch (input[i]) {
		case '(':
			SPush(&stack, small);
			break;
		case '[':
			SPush(&stack, big);
			break;
		case ')':
			if (stack.topIndex == -1)
			{
				printf("0\n");
				return(FALSE);
			}
			if (SPop(&stack) != small)
			{
				printf("0\n");
				return (FALSE);
			}
			break;
		case ']':
			if (stack.topIndex == -1)
			{
				printf("0\n");
				return (FALSE);
			}
			if (SPop(&stack) != big)
			{
				printf("0\n");
				return (FALSE);
			}
			break;
		}
		++i;
	}
	if (!SIsEmpty(&stack))
	{
		printf("0\n");
		return (FALSE);
	}

	i = 0;
	
	while (i < len)
	{
		sum = 0;
		switch (input[i]) {
		case '(':
			SPush(&stack, small);
			break;
		case '[':
			SPush(&stack, big);
			break;
		case ')':
			while ((num = SPop(&stack)) != small)
				sum += num;
			if (!sum)
				SPush(&stack, 2);
			else
				SPush(&stack, sum * 2);
			break;
		case ']':
			while ((num = SPop(&stack)) != big)
				sum += num;
			if (!sum)
				SPush(&stack, 3);
			else
				SPush(&stack, sum * 3);
			break;
		}
		++i;
	}
	sum = 0;
	while (!SIsEmpty(&stack))
		sum += SPop(&stack);
	printf("%d\n", sum);
	return(0);
}
