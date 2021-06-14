#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)	// �켱 ������ ���� �ڽ� ��� �ε��� ��ȯ
{
	if(GetLChildIDX(idx) > ph->numOfData)	// �ڽ� ��尡 ������ 0 ��ȯ
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)	// �ڽ� ��尡 �ϳ��� ���� ��� ��ȯ
		return GetLChildIDX(idx);

	else	// �켱 ���� ���� ��� ��ȯ
	{
	//	if(ph->heapArr[GetLChildIDX(idx)].pr 
	//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
	HData retData = ph->heapArr[1];		// ��ȯ�� ���� ��Ʈ ��� �� ����
	HData lastElem = ph->heapArr[ph->numOfData];	// ������ ����� ���� ��忡 �ִ� �����ϰ� ���� 

	int parentIdx = 1;
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // �켱���� ���� �ڽ� ��� �ε���
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) // �� �������� �ٲ� �� ��� �ߴ�
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];		// �켱���� ���� �ڽ� ���� �θ� ��� �ٲ�
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}