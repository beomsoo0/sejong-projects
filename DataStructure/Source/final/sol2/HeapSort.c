#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2-n1;
//	return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);


	// ���� ����� ������ ���� �����Ѵ�.
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}

int main(void)
{
	int arr[100];
	int N, X;
	scanf("%d %d", &N, &X);
	int i = 0;
	while (i < N)
	{
		scanf(" %d", &arr[i++]);
	}

	HeapSort(arr, sizeof(int) * N, PriComp);
	int flag = -1;
	i = 0;
	while (i < N)
	{
		if (arr[i] == X)
		{
			printf("%d", N - i);
			flag = 1;
		}
		++i;
	}
	if (flag == -1)
		printf("%d", flag);
	printf("\n");
	return 0;
}
