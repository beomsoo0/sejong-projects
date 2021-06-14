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

int GetHiPriChildIDX(Heap * ph, int idx)	// 우선 순위가 높은 자식 노드 인덱스 반환
{
	if(GetLChildIDX(idx) > ph->numOfData)	// 자식 노드가 없으면 0 반환
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)	// 자식 노드가 하나면 왼쪽 노드 반환
		return GetLChildIDX(idx);

	else	// 우선 순위 높은 노드 반환
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
	HData retData = ph->heapArr[1];		// 반환을 위해 루트 노드 값 저장
	HData lastElem = ph->heapArr[ph->numOfData];	// 마지막 노드의 값을 노드에 있다 생각하고 진행 

	int parentIdx = 1;
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // 우선순위 높은 자식 노드 인덱스
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) // 더 내려가며 바꿀 곳 없어서 중단
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];		// 우선순위 높은 자식 노드와 부모 노드 바꿈
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}