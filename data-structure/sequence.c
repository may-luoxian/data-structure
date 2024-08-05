#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ˳�����̬����
// ��ʼ��˳���
void initList(StaticSeqList* L) {
	for (int i = 0; i < MAX_SIZE; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
}

// �������
bool ListInsert(StaticSeqList* L, int i, int e) {
	int length = ARRAY_LENGTH(L->data);
	if (L->length >= length) {
		printf("˳�������������Ϊ%d\n", L->length);
		return false;
	}

	if (i < 0 || i > L->length) {
		printf("����������Ϸ����밴�����\n");
		return false;
	}

	// ����i����֮���Ԫ�غ���
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	// ��i���洢e
	L->data[i] = e;
	// ���鳤�ȼ�һ
	L->length++;

	return true;
}

// ɾ������
int ListDelete(StaticSeqList* L, int i) {
	// �ж�i�Ƿ�Ϸ�
	if (i < 0 || i > L->length - 1) {
		printf("ɾ���������Ϸ���i��������Ԫ��\n");
		return -1;
	}

	int result = L->data[i];

	// ����i�������Ԫ��ǰ��
	for (int j = i; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	// ���Ա��ȼ�һ
	L->length--;
	return result;
}

// ��̬˳�����Ҳ����ܼ򵥣������ظ�

// ��ӡ˳���
void printSeqList(StaticSeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
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

// ��̬�������ɾ�����뾲̬˳������ƣ��ʲ����ظ�

// ĩβ�������
void addData(DynamicSeqList* L, int val) {
	if (L->length >= L->MaxSize) {
		printf("˳�������������Ϊ%d\n", L->length);
		return;
	}
	L->data[L->length] = val;
	L->length++;
}

// ��λ����
int GetElem(DynamicSeqList* L, int i) {
	if (i < 0 || i > L->length) {
		printf("���Ҳ������Ϸ���i��������Ԫ��\n");
		return -1;
	}

	return L->data[i];
}

// ��ֵ����
int LocateElem(DynamicSeqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i;
		}
	}
	return -1;
}

// ��ӡ˳���
void printDynamicSeqList(DynamicSeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}