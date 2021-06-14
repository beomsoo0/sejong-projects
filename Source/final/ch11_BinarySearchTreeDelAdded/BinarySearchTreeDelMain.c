#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

	int N, X, k;
	scanf("%d %d", &N, &X);
	int i = 0;
	int cnt;
	BSTMakeAndInit(&bstRoot);
	while (i < N)
	{
		scanf(" %d", &k);
		BSTInsert(&bstRoot, k);
		++i;
	}
	//cnt = BSTfind(&bstRoot, X);
	//printf("%d\n", cnt);
	cnt = BSTFind(&bstRoot, X);
	printf("%d\n", cnt);
	//BSTShowAll(bstRoot); printf("\n");
	//sNode = BSTRemove(&bstRoot, 3);
	//free(sNode);


	return 0;
}