#include <stdio.h>
#include "ALGraphKruskal.h"

int main(void)
{
	int N, M, x, y, i;
	ALGraph graph;

	scanf("%d %d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * (N * N));
	i = 0;
	while (i < N * N)
		scanf(" %d", &arr[i++]);

	GraphInit(&graph, N);

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			if (arr[y * N + x] == 1)
				AddEdge(&graph, y, x);
			++x;
		}
		++y;
	}
	int* arr2 = (int*)calloc(N * N, sizeof(int));
	//ShowGraphEdgeInfo(&graph);
	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			if (x % N == N - 1)
				printf("%d", IsConnVertex(&graph, y, x));
			else
				printf("%d ", IsConnVertex(&graph, y, x));
			++x;
			//memset(graph.visitInfo, 0, sizeof(int) * pg->numV);
		}
		printf("\n");
		++y;
	}
	return 0;
}