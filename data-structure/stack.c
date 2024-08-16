#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ��˳��ջ
void InitSeqStack(SeqStack* S) {
	S->top = -1;
}

// ��ջ����
bool Push(SeqStack* S, int x) {
	if (S->top == MAX_SIZE - 1) {
		printf("ջ��");
		return false;
	}
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}

// ��ջ����
int Pop(SeqStack* S) {
	if (S->top == -1) {
		printf("ջ��");
		return -1;
	}
	int e = S->data[S->top];
	/*S->data[S->top] = NULL;*/ // ���ݲ������߼�ɾ��
	S->top = S->top - 1;
	return e;
}

// ��ջ��Ԫ��
int GetTop(SeqStack S) {
	if (S.top == -1) {
		printf("ջ��");
		return -1;
	}
	return S.data[S.top];
}