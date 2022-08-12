#include <stdio.h>

void	print_Pre(int is, int ie, int ps, int pe);

int		g_Inorder[100000];
int		g_Postorder[100000];
int		g_Position[100001];

int		main(void)
{
	int N, i;
	scanf("%d", &N);
	i = 0;
	while (i < N)
		scanf(" %d", &g_Inorder[i++]);
	i = 0;
	while (i < N)
		scanf(" %d", &g_Postorder[i++]);
	i = 0;
	while (i < N)
	{
		g_Position[g_Inorder[i]] = i;
		++i;
	}
	print_Pre(0, N - 1, 0, N - 1);
	return (0);
}

void	print_Pre(int is, int ie, int ps, int pe)
{
	int root, ir;

	if ((is > ie) || (ps > pe))
		return ;

	root = g_Postorder[pe];
	ir = g_Position[root];
	printf("%d ", root);
	print_Pre(is, ir - 1, ps, ps + ir - is - 1);
	print_Pre(ir + 1, ie, ps + ir - is, pe - 1);
}