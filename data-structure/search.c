#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "data-type.h"
#include "sequence.h"
#include "sort.h"

void initValue(DynamicSeqList* sl) {
	srand(time(NULL));
	for (int i = 0; i < sl->MaxSize; i++)
	{
		sl->data[i] = rand() % 100;
		sl->length++;
	}
}

// 顺序查找（顺序表）
void searchSearchTest() {
	DynamicSeqList seqlist;
	InitDynaticSeqList(&seqlist);
	initValue(&seqlist);
	
	//quick_sort(seqlist.data, 0, seqlist.length - 1);
	int index = Search_Search(seqlist, 46);
	printf("\n%d", index);
}

// 顺序查找操作
int Search_Search(DynamicSeqList sl, int key) {
	int i;
	for (i = 0; i < sl.length && sl.data[i] != key; i++); // 继续遍历条件：length小于数组长度，且当前元素不等于关键字
	
	return i == sl.length ? -1 : i;
}

// 折半查找（二分查找）
void binarySearchTest() {
	DynamicSeqList seqlist;
	InitDynaticSeqList(&seqlist);
	initValue(&seqlist);

	quick_sort(seqlist.data, 0, seqlist.length - 1);
	int index = Binary_Search(seqlist, 66);
	printf("\n%d", index);
}

// 折半查找操作
int Binary_Search(DynamicSeqList sl, int key) {
	int low = 0, high = sl.length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2; // mid取中间位置
		if (key == sl.data[mid]) {
			return mid;
		}
		else if (key < sl.data[mid]) // key小于中值，high指向mid-1
		{
			high = mid - 1;
		}
		else // key大于中值，low指向mid+1
		{
			low = mid + 1;
		}
	}
	return -1;
}