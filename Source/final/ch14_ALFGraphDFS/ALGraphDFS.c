#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // �ʱ��� ���� ���� 0��

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	// Ž�� ���� ����� ���� ������ �Ҵ� �� �ʱ�ȭ
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

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg)
{
	List	*rpos = pg->adjList;
	List	*tmp = rpos;
	int		i = 0;

	if (pg->adjList != NULL)
	{
		// ��� ����
		printf("���� ��带 �����մϴ�\n");
		while (i++ < pg->numV)
		{
			rpos = tmp++;
			printf("%c�� ����� ���� : ", i - 1 + 'A');
			LRemoveAll(rpos);
			printf("\n");
		}
		pg->numE = 0;				// ���� �� NULL
		// ����Ʈ ����
		printf("����Ʈ�� �����մϴ�\n");
		free(pg->adjList);			// adjlist ����
		free(pg->visitInfo);		// visit ����
		pg->numV = 0;				// ��� �� NULL
	}
}

// ������ �߰�
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);		//������� �����ϸ� �ɵ�?
	pg->numE += 1;
}

// ��ƿ��Ƽ �Լ�: ������ ���� ���
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);
		
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
		printf("%c ", visitV + 65);     // �湮 ���� ���
		return TRUE;
	}
	
	return FALSE;
}

// Depth First Search: ������ ���� ���
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	// DFS�� ���� ������ �ʱ�ȭ
	StackInit(&stack);

	VisitVertex(pg, visitV);    // ���� ���� �湮
	//SPush(&stack, visitV);		// ù ��� Ǫ��

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
			if(SIsEmpty(&stack) == TRUE)    // ������ ��� DFS����
				break;
			else
				visitV = SPop(&stack);	
		}
	}

	// Ž�� ���� �ʱ�ȭ
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