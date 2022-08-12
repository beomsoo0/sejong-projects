#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

int LInsert(List* plist, LData data)
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
	while (i <= max - index - 1)
	{
		plist->arr[max - i] = plist->arr[max - i - 1];
		i++;
	}
	plist->arr[index] = data;
	(plist->numOfData)++;
	return TRUE;
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}