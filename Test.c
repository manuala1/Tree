#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include <time.h>


void TestHeap1() {
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 65);
	HeapPush(&hp, 100);
	HeapPush(&hp, 70);
	HeapPush(&hp, 32);
	HeapPush(&hp, 50);
	HeapPush(&hp, 60);
	HeapPrint(&hp);
	HeapDestroy(&hp);
}
void TestHeap2() {
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 65);
	HeapPush(&hp, 100);
	HeapPush(&hp, 70);
	HeapPush(&hp, 32);
	HeapPush(&hp, 50);
	HeapPush(&hp, 60);
	while (!HeapEmpty(&hp)) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapPrint(&hp);
	HeapDestroy(&hp);
}
//void HeapSort(int* a, int n) {
//	HP hp;
//	HeapInit(&hp);
//	for (size_t i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		a[i]=HeapTop(&hp);
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}
void HeapSort(int* a, int n) {
	 //建堆  降序小堆 升序大堆
	//向上调整建堆 O(N*logN)
	/*for (size_t i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	//向下调整建堆 O(N)
	int pos = (n-1-1)/ 2;
	while (pos > 0) {
		AdjustDown(a, n, pos);
		pos--;
	}
	int end = n - 1;
	while (end > 0) {
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
	/*for (size_t i = 0; i < n; i++)
	{
		swap(&a[0], &a[n - 1 - i]);
		AdjustDown(a, n-i-1, 0);
	}*/
	
}
void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	int* kminheap = (int*)malloc(sizeof(int) * k);
	for (size_t i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}
	//向下调整成为堆
	for (size_t i = (k-1-1)/2; i>0 ; i--)
	{
		AdjustDown(kminheap, i, 0);
	}
	int tmp = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &tmp);
		if (tmp> kminheap[0])
		{
			kminheap[0] = tmp;
			AdjustDown(kminheap, k, 0);
		}
	}
	for (size_t i = 0; i < k; i++)
	{
		printf("%d\n", kminheap[i]);
	}
	free(kminheap);
}
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BuyNode(BTDataType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = node->_right = NULL;
	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
    BTNode * node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	return node1;
}
void PreOrder(BTNode* root) {
	if (root==NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->_data);
	PreOrder(root->_left);
	PreOrder(root->_right);
}

void InOrder(BTNode* root) {
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}


int main() {
	/*int a[] = { 7,8,3,5,1,9,5,4 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}*/
	//PrintTopK(10);
	BTNode* root=CreatBinaryTree();
	InOrder(root);
	return 0;
}