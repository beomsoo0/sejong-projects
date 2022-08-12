#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define LIST_LEN	1000010

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* before;
} Node;

typedef struct _linkedList
{
	Node* head;
	Node* tail;
	Node* cur;
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->next = plist->tail;
	plist->head->before = NULL;
	plist->head->data = NULL;

	plist->tail->before = plist->head;
	plist->tail->next = NULL;
	plist->tail->data = NULL;

	plist->cur = plist->head;
}

void LInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->cur->next;
	newNode->before = plist->cur;

	plist->cur->next->before = newNode;
	plist->cur->next = newNode;
	plist->cur = newNode;	
}

void LRemove(List* plist)
{
	Node* rpos = plist->cur;

	plist->cur->before->next = plist->cur->next;
	plist->cur->next->before = plist->cur->before;
	plist->cur = plist->cur->before;

	free(rpos);
}

void LPrint(List* plist)
{
	Node* p = plist->head->next;
	while (p != plist->tail)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int	main(void)
{
	LinkedList list;
	int N, len, i, data;
	char input[LIST_LEN];

	scanf("%d", &N);
	while (N--)
	{
		memset(input, 0, LIST_LEN);
		scanf("%s", input);
		len = strlen(input);

		ListInit(&list);
		i = 0;
		while (i < len)
		{
			if (input[i] == '<')
			{
				if (list.cur != list.head)
					list.cur = list.cur->before;
			}
			else if (input[i] == '>')
			{
				if (list.cur->next != list.tail)
					list.cur = list.cur->next;
			}
			else if (input[i] == '-')
			{
				if (list.cur->data != NULL)
					LRemove(&list);
			}
			else
				LInsert(&list, input[i]);
			++i;
		}
		LPrint(&list);
	}
	return (0);
}