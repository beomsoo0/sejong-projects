#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // 초기의 간선 수는 0개

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	// 탐색 정보 등록을 위한 공간의 할당 및 초기화
	pg->visitInfo= (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void LRemoveAll(List* plist)
{
	Node* rpos = plist->head->next;
	Node* tmp = rpos;
	while (tmp != NULL)
	{
		rpos = tmp;
		tmp = rpos->next;
		printf("%c ", rpos->data + 'A');
		free(rpos);
		(plist->numOfData)--;
	}
	plist->head->next = NULL;
}

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg)
{
	List	*rpos = pg->adjList;
	List	*tmp = rpos;
	int		i = 0;

	if (pg->adjList != NULL)
	{
		// 노드 제거
		printf("연결 노드를 제거합니다\n");
		while (i++ < pg->numV)
		{
			rpos = tmp++;
			printf("%c와 연결된 접점 : ", i - 1 + 'A');
			LRemoveAll(rpos);
			printf("\n");
		}
		pg->numE = 0;				// 간선 수 NULL
		// 리스트 제거
		printf("리스트를 제거합니다\n");
		free(pg->adjList);			// adjlist 해제
		free(pg->visitInfo);		// visit 해제
		pg->numV = 0;				// 노드 수 NULL
	}
}

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);		//유방향시 제거하면 될듯?
	pg->numE += 1;
}

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);
		
		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}


int VisitVertex(ALGraph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);     // 방문 정점 출력
		return TRUE;
	}
	
	return FALSE;
}

// Depth First Search: 정점의 정보 출력
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	// DFS를 위한 스택의 초기화
	StackInit(&stack);

	VisitVertex(pg, visitV);    // 시작 정점 방문
	//SPush(&stack, visitV);		// 첫 노드 푸쉬

	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		
		if(visitFlag == FALSE)
		{
			if(SIsEmpty(&stack) == TRUE)    // 스택이 비면 DFS종료
				break;
			else
				visitV = SPop(&stack);	
		}
	}

	// 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int IsConnVertex(ALGraph* pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;
	int flag = 0;
	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (nextV == v2)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			flag = 1;
		}

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{

				if (nextV == v2)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					flag = 1;
				}

				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return flag;
}