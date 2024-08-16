#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ³õÊ¼»¯Ë³ÐòÕ»
void InitSeqStack(SeqStack* S) {
	S->top = -1;
}

// ½øÕ»²Ù×÷
bool Push(SeqStack* S, int x) {
	if (S->top == MAX_SIZE - 1) {
		printf("Õ»Âú");
		return false;
	}
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}

// ³öÕ»²Ù×÷
int Pop(SeqStack* S) {
	if (S->top == -1) {
		printf("Õ»¿Õ");
		return -1;
	}
	int e = S->data[S->top];
	/*S->data[S->top] = NULL;*/ // Êý¾Ý²ÐÁô£¬Âß¼­É¾³ý
	S->top = S->top - 1;
	return e;
}

// ¶ÁÕ»¶¥ÔªËØ
int GetTop(SeqStack S) {
	if (S.top == -1) {
		printf("Õ»¿Õ");
		return -1;
	}
	return S.data[S.top];
}