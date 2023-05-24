#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPrint(HP* php);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
void AdjustDown(HPDataType* a, int size, int father);
void AdjustUp(HPDataType* a, int child);
void swap(HPDataType* p1, HPDataType* p2);

