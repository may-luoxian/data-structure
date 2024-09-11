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

// ˳����ң�˳���
void searchSearchTest() {
	DynamicSeqList seqlist;
	InitDynaticSeqList(&seqlist);
	initValue(&seqlist);
	
	//quick_sort(seqlist.data, 0, seqlist.length - 1);
	int index = Search_Search(seqlist, 46);
	printf("\n%d", index);
}

// ˳����Ҳ���
int Search_Search(DynamicSeqList sl, int key) {
	int i;
	for (i = 0; i < sl.length && sl.data[i] != key; i++); // ��������������lengthС�����鳤�ȣ��ҵ�ǰԪ�ز����ڹؼ���
	
	return i == sl.length ? -1 : i;
}

// �۰���ң����ֲ��ң�
void binarySearchTest() {
	DynamicSeqList seqlist;
	InitDynaticSeqList(&seqlist);
	initValue(&seqlist);

	quick_sort(seqlist.data, 0, seqlist.length - 1);
	int index = Binary_Search(seqlist, 66);
	printf("\n%d", index);
}

// �۰���Ҳ���
int Binary_Search(DynamicSeqList sl, int key) {
	int low = 0, high = sl.length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2; // midȡ�м�λ��
		if (key == sl.data[mid]) {
			return mid;
		}
		else if (key < sl.data[mid]) // keyС����ֵ��highָ��mid-1
		{
			high = mid - 1;
		}
		else // key������ֵ��lowָ��mid+1
		{
			low = mid + 1;
		}
	}
	return -1;
}