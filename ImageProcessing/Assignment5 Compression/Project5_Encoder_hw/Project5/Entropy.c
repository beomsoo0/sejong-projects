#include "Encoder.h"

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
	Int size = 0;

	for (Int i = 0; i < 16; i++)
	{
		img->Huff_ch[i] = 10000;
		img->Huff_freq[i] = 0;
		img->Huff_codes[i] = 0;
		img->Huff_length[i] = 0;
	}
	img->Huff_Size = 0;

	for (Int i = 0; i < 16; i++)
	{
		Int flag = 0;
		img->Quant_blk[i];
		for (Int j = 0; j < 16; j++)
		{
			if (img->Quant_blk[i] == img->Huff_ch[j] && flag == 0)
			{
				flag = 1;
				img->Huff_freq[j]++;
			}
		}
		if (flag == 0)
		{
			img->Huff_ch[size] = img->Quant_blk[i];
			img->Huff_freq[size++]++;
		}
	}
	
	huffman_tree(img->Huff_freq, img->Huff_ch, size, img);
	img->Huff_Size = size;
}

void Entropy(Int BLK, Int Blk_Row, Int Blk_COl, Img_Buf* img)
{
	FILE* fp;

	Int ALL_Zero_flag = 1; //����ȭ�� ��ȯ ��� �� ȭ�Ұ����� ���� 0�� ���

	UChar cur_info = 0;
	UChar bitstream = 0;
	UChar bit_cnt = 0;
	UChar tmp = 0;
	UChar buf_binary[16] = { 0 };

	fopen_s(&fp, "Bitstream.raw", "ab");

	for (Int i = 0; i < BLK * BLK; i++)
		if (img->Quant_blk[i] != 0)
		{
			ALL_Zero_flag = 0;
			break;
		}
															//0000 0000
	if (ALL_Zero_flag) //0000 0000
		bitstream = 0xC0; // ������: 1100 0000				// �� 0 -> 1100 0000
	switch (img->info.Best_Mode)
	{
	case 0:
		bitstream |= 0x30; // ������: 11 0000
		break;
	case 1:
		bitstream |= 0x0C; // ������: 00 1100
		break;
	case 2:
		bitstream |= 0x03; // ������: 00 0011
		break;
	case 3:
		bitstream |= 0x00; // ������: 00 0000
		break;
	}
	fwrite(&bitstream, sizeof(UChar), 1, fp);
	bitstream = 0;

	

	if (!ALL_Zero_flag)
	{
		

		Char bitstream2;

		Huffman(img);

		bitstream2 = img->Huff_Size;
		fwrite(&bitstream2, sizeof(Char), 1, fp);

		for (Int i = 0; i < img->Huff_Size; i++)
		{			
			bitstream2 = img->Huff_ch[i];
			fwrite(&bitstream2, sizeof(Char), 1, fp);
			bitstream2 = img->Huff_freq[i];
			fwrite(&bitstream2, sizeof(Char), 1, fp);
		}
		bitstream = 0;

		Int Idx = 0;
		for (Int i = 0; i < BLK * BLK; i++)
		{
			for (Int j = 0; j < img->Huff_Size; j++)
			{
				if (img->Quant_blk[i] == img->Huff_ch[j])
					Idx = j;
			}
			
			tmp = img->Huff_codes[Idx];
			for (int q = 0; tmp > 0; q++) {									//����ȭ �Ųٷ� ����
				buf_binary[q] = tmp % 2;
				tmp /= 2;
			}
			for (int q = 0; q < img->Huff_length[Idx]; q++) {
				bitstream <<= 1;											//��ĭ Shift
				bitstream |= buf_binary[img->Huff_length[Idx] -1 - q];		
				bit_cnt++;
				if (bit_cnt == 8) {
					fwrite(&bitstream, sizeof(UChar), 1, fp);
					bit_cnt = 0;
				}
			}
		}

		if (bit_cnt != 8)
		{
			bitstream <<= (8 - bit_cnt);
			fwrite(&bitstream, sizeof(UChar), 1, fp);
		}
	}
	

	fclose(fp);
}
