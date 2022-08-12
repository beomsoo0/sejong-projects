#include <stdio.h>

#define TRUE	1
#define FALSE	0


#define LIST_LEN	100
typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LLastInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
		return FALSE;

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
	return TRUE;
}

int LInsertPosition(List* plist, int index, LData data)
{
	if ((plist->numOfData >= LIST_LEN) || (index > plist->numOfData))
		return FALSE;
	int i = 0;
	int max = plist->numOfData;
	while (i <= max -index -1)
	{
		plist->arr[max - i] = plist->arr[max - i - 1];
		i++;
	}
	plist->arr[index] = data;
	(plist->numOfData)++;
	return TRUE;
}


int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}
int main(void)
{
	List list;
	int data;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	LFirst(&list, &data);

	LLastInsert(&list, 100);
	LInsertPosition(&list, 6, 3);
	LLastInsert(&list, 200);
	if (LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}