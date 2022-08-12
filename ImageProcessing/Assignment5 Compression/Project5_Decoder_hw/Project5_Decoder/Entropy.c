#include "Decoder.h"

#define MAX_ELEMENT 200

typedef struct TreeNode {
	int CNT;
	int ch;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

typedef struct {
	TreeNode* ptree;
	int ch;
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

//�ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}

//���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
//���� �Լ�
void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��� ����
}

//���� �Լ�
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key) break;

		//�� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//���� Ʈ�� ���� �Լ�
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

//���� Ʈ�� ���� �Լ�
void destroy_tree(TreeNode* root)
{
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root)
{
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n, Int Idx, Img_Buf* img)
{
	for (int i = 0; i < n; i++)
	{
		img->Huff_codes[Idx] <<= 1;
		if (codes[i] == 1)
		{
			img->Huff_codes[Idx] |= 1;
		}
	}
	img->Huff_length[Idx] = n;
}

void print_codes(TreeNode* root, int codes[], int top, Img_Buf* img)
{
	//1�� �����ϰ� ��ȯȣ���Ѵ�.
	if (root->left)
	{
		codes[top] = 1;
		print_codes(root->left, codes, top + 1, img);
	}
	//0�� �����ϰ� ��ȯȣ���Ѵ�.
	if (root->left)
	{
		codes[top] = 0;
		print_codes(root->right, codes, top + 1, img);
	}
	//�ܸ�����̸� �ڵ带 ����Ѵ�.
	if (is_leaf(root))
	{
		Int Idx = 0;
		for (Int i = 0; i < 16; i++)
		{
			if (root->ch == img->Huff_ch[i])
			{
				Idx = i;
				break;
			}
		}
		print_array(codes, top, Idx, img);
	}
}

//������ �ڵ� ���� �Լ�
void huffman_tree(int freq[], int ch_list[], int n, Img_Buf* img)
{
	TreeNode* node, * x;
	HeapType* Set;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	Set = create();
	init(Set);
	for (int i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->CNT = freq[i];
		e.ptree = node;
		insert_min_heap(Set, e);
	}

	for (int i = 1; i < n; i++) {
		//�ּҰ��� ������ �� ���� ��带 ����
		e1 = delete_min_heap(Set);
		e2 = delete_min_heap(Set);

		//�ΰ��� ��带 ��ģ��. 
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->CNT = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(Set, e);
	}
	e = delete_min_heap(Set);
	print_codes(e.ptree, codes, top, img);
	destroy_tree(e.ptree);
	free(Set);
}

void Huffman(Img_Buf* img)
{
	Int size = img->Huff_Size;

	huffman_tree(img->Huff_freq, img->Huff_ch, size, img);
}

void Entropy(Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img, File_Info* file)
{


	Int ALL_Zero_flag = 0; //����ȭ�� ��ȯ ��� �� ȭ�Ұ����� ���� 0�� ���
	UChar bitstream = 0;

	Char bitstream2;
	UChar mode = 0;
	fread(&bitstream, sizeof(UChar), 1, file->Input_Bitstream);


	for (int q = 0; q < 8; q++) {
		mode << 1;
		mode = (mode |= (bitstream % 2));
		bitstream /= 2;
	}


	//����ȭ�� ��ȯ ��� �� ��� ������ 0�ΰ�?
	//??
	if (mode != 0xC0) {
		ALL_Zero_flag = 1;
	}

	//���� ���
	//??
	if (!ALL_Zero_flag){
		if (mode == 0xf0) {
			img->info.Best_Mode = DC;
		}
		else if (mode == 0xcc) {
			img->info.Best_Mode = VERTICAL;
		}
		else if (mode == 0xc3) {
			img->info.Best_Mode = HORIZONTAL;
		}
		else if (mode == 0xc0) {
			img->info.Best_Mode = DIAGONAL;
		}
	}

	if (!ALL_Zero_flag)
	{
		Int Bits_flag[16] = { 0 };

		for (Int i = 0; i < 16; i++)
		{
			img->Huff_ch[i] = 10000;
			img->Huff_freq[i] = 0;
			img->Huff_codes[i] = 0;
			img->Huff_length[i] = 0;
		}
		img->Huff_Size = 0;

		fread(&bitstream2, sizeof(Char), 1, file->Input_Bitstream);
		img->Huff_Size = bitstream2;

		for (Int i = 0; i < img->Huff_Size; i++)
		{
			fread(&bitstream2, sizeof(Char), 1, file->Input_Bitstream);
			img->Huff_ch[i] = bitstream2;
			
			fread(&bitstream2, sizeof(Char), 1, file->Input_Bitstream);
			img->Huff_freq[i] = bitstream2;
		}
		
		Huffman(img);
		bitstream = 0;

		Int Idx = -1;
		UChar cur_info = 0;
		UChar bit_cnt = 0;
		UChar tmp = 0;
		Int Coeff_Num = 0;
		Int Lenth_Num = 0;
		fread(&bitstream, sizeof(UChar), 1, file->Input_Bitstream);
		while (Coeff_Num != 16)
		{
			//bitstream���� 1��Ʈ�� �о��
			bit_cnt << 1;
			bit_cnt = bit_cnt |= (bitstream % 2);
			bitstream /= 2;
			//??
			//??
			//??
			Lenth_Num++;//1��Ʈ �о�ö����� ����

			Int Break_flag = 0;
			for (Int j = 0; j < img->Huff_Size; j++) //���� �о�� �ڵ����� ������ �ɺ��� �ڵ���尡 �����ϴ��� �Ǵ��ϱ� ���� �ݺ���
			{
				if (cur_info == img->Huff_codes[j] && Break_flag == 0)
				{
					//Idx�� ����
					//??
					if (Idx != -1 && //�ɺ� �ڵ���尡 ��ġ�Ѵٸ� �ڵ���� ���̱��� ��ġ�ϴ°�?)
					{
						//����ȭ�� ��ȯ ��� ����
						//���ε��� �� ���� �ʱ�ȭ
						//?
						//?
						Break_flag = 1;
					}
				}
			}
			
			if(Break_flag==0)
			{
				//
			}
			bit_cnt++;
			if (bit_cnt == 8 && Coeff_Num!=16)
			{
				fread(&bitstream, sizeof(UChar), 1, file->Input_Bitstream);
				bit_cnt = 0;
			}
		}

	}
}
