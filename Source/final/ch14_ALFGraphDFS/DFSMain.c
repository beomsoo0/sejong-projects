#include <stdio.h>
#include "ALGraphDFS.h"

int IsConnVertex(ALGraph* pg, int v1, int v2);

int main(void)
{
	int N, M, x, y, i;
	ALGraph graph;
	
	scanf("%d %d", &N, &M);
	GraphInit(&graph, N);
	i = 0;
	int a, b;
	while (i < N * N)
	{
		scanf(" %d %d", &y, &x);
		AddEdge(&graph, y-1, x-1);
		++i;
	}

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			printf("%d ", IsConnVertex(&graph, y, x));
			++x;
			//memset(graph.visitInfo, 0, sizeof(int) * pg->numV);
		}
		printf("\n");
		++y;
	}
	return 0;
}