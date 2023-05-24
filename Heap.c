#include "Heap.h"
void HeapInit(HP* php) {
    assert(php);
    php->a =NULL;
	php->size = 0;
	php->capacity = 0;
}
void swap(HPDataType* p1, HPDataType* p2) {
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapDestroy(HP* php) {
	assert(php);
	free(php->a);
	php->capacity = 0;
	php->size = 0;
	php->a = NULL;
}
void AdjustUp(HPDataType* a,int child) {
	while (child)
	{
		int father = (child - 1) / 2;
		if (a[child]<a[father])
		{
			swap(&a[child], &a[father]);
			child = father;
		}
		else
		{
			break;
		}
		
	}

}
void HeapPush(HP* php, HPDataType x) {
	assert(php);
	if (php->capacity == php->size) {
		int newSize = php->capacity == 0 ? 4 : (2 * php->capacity);
		HPDataType* tmp= (HPDataType*)realloc(php->a,sizeof(HPDataType)*newSize);
		if (tmp ==NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a=tmp;
		php->capacity = newSize;
	}
	php->a[(php->size)++] = x;
	AdjustUp(php->a, php->size - 1);

}
void HeapPrint(HP* php) {
	assert(php);
	for (size_t i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}

}
void AdjustDown(HPDataType* a,int size,int father) {
	int child = father * 2 + 1;
	while (child<size) {
		if (child+1<size&&a[child+1]<a[child])//右孩子存在且右孩子小于左孩子
		{
			child++;
		}
		if (a[child]<a[father])
		{
			swap(&a[father], &a[child]);
			father = child;
			child = father * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
void HeapPop(HP* php) { //删除堆顶数据
	assert(php);
	assert(!HeapEmpty(php));
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a,php->size,0);

}
HPDataType HeapTop(HP* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

bool HeapEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}
int HeapSize(HP* php) {
	assert(php);
	return php->size;
}