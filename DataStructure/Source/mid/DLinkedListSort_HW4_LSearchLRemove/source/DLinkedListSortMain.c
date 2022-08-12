#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if(d1 > d2)
		return 0;    // d1이 정렬 순서상 앞선다.
	else
		return 1;    // d2가 정렬 순서상 앞서거나 같다.
}

int main(void)
{
	// List의 생성 및 초기화  ////////////
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	// 5개의 데이터 저장  ///////////////
	LInsert(&list, 71);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 33);
	LInsert(&list, 33);  LInsert(&list, 52);

	// 저장된 데이터의 전체 출력 ////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) 
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22있는지 탐색////////////////
	if (LSearch(&list, 22) == -1)
		printf("리스트에 22가 없습니다\n");
	else
		printf("%d번째 idx에 22가 있습니다\n", LSearch(&list, 22));
	printf("\n");
	
	// 첫 33 삭제//////////////////////
	if (LRemoveData(&list, 33))
		printf("첫번째 33을 제거하였습니다.\n");
	else
		printf("33이 존재하지 않습니다\n");
	printf("\n");

	/*
	// 숫자 22을 검색하여 모두 삭제 ////////////
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}*/

	// 삭제 후 저장된 데이터 전체 출력 ////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}