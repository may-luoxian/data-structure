#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 顺序表—静态分配
// 初始化顺序表
void initList(StaticSeqList* L) {
	for (int i = 0; i < MAX_SIZE; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
}

// 插入操作
bool ListInsert(StaticSeqList* L, int i, int e) {
	int length = ARRAY_LENGTH(L->data);
	if (L->length >= length) {
		printf("顺序表已满，长度为%d\n", L->length);
		return false;
	}

	if (i < 0 || i > L->length) {
		printf("插入操作不合法，请按序插入\n");
		return false;
	}

	// 将第i个及之后的元素后移
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	// 在i处存储e
	L->data[i] = e;
	// 数组长度加一
	L->length++;

	return true;
}

// 删除操作
int ListDelete(StaticSeqList* L, int i) {
	// 判断i是否合法
	if (i < 0 || i > L->length - 1) {
		printf("删除操作不合法，i处不存在元素\n");
		return -1;
	}

	int result = L->data[i];

	// 将第i个往后的元素前移
	for (int j = i; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	// 线性表长度减一
	L->length--;
	return result;
}

// 静态顺序表查找操作很简单，不再重复

// 打印顺序表
void printSeqList(StaticSeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

// 顺序表—动态分配
// 初始化顺序表
void initDynaticList(DynamicSeqList* L) {
	L->data = (int*)malloc(INIT_SIZE * sizeof(int));
	L->length = 0;
	L->MaxSize = INIT_SIZE;
}

// 增加顺序表长度
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

// 动态分配的增删操作与静态顺序表类似，故不再重复

// 末尾添加数据
void addData(DynamicSeqList* L, int val) {
	if (L->length >= L->MaxSize) {
		printf("顺序表已满，长度为%d\n", L->length);
		return;
	}
	L->data[L->length] = val;
	L->length++;
}

// 按位查找
int GetElem(DynamicSeqList* L, int i) {
	if (i < 0 || i > L->length) {
		printf("查找操作不合法，i处不存在元素\n");
		return -1;
	}

	return L->data[i];
}

// 按值查找
int LocateElem(DynamicSeqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i;
		}
	}
	return -1;
}

// 打印顺序表
void printDynamicSeqList(DynamicSeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}