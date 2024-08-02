#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "data-type.h"

// ˳�����̬����
// ��ʼ��˳���
void initList(StaticSeqList* L) {
	for (int i = 0; i < MAX_SIZE; i++) {
		L->data[i] = 0;
	}
	L->length = MAX_SIZE;
}

// ��ӡ˳���
void printSeqList(StaticSeqList L) {
	int length = L.length;
	for (int i = 0; i < length; i++) {
		printf("%d ", L.data[i]);
	}
}

// ˳�����̬����
// ��ʼ��˳���
void initDynaticList(DynamicSeqList* L) {
	L->data = (int*)malloc(INIT_SIZE * sizeof(int));
	L->length = 0;
	L->MaxSize = INIT_SIZE;
}

// ����˳�����
void increaseSize(DynamicSeqList* L, int len) {
	int* p = L->data;
	int MaxSize = L->MaxSize + len;
	L->data = (int*)malloc(MaxSize * sizeof(int));
	for (int i = 0; i < L->length; i++) {
		if (L->data != NULL) {
			L->data[i] = p[i];
		}
	}
	L->MaxSize = MaxSize;
	free(p);
}

// ĩβ�������
void addData(DynamicSeqList* L, int val) {
	if (L->length >= L->MaxSize) {
		printf("˳�������������Ϊ%d\n", L->length);
		return;
	}
	L->data[L->length] = val;
	L->length++;
}

// ��ӡ˳���
void printDynamicSeqList(DynamicSeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}