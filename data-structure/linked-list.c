#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ��������-����ͷ�ڵ�
bool InitLinkedList(LinkedList* L) {
	*L = NULL;
	return true;
}

// ��ʼ��������-��ͷ�ڵ�
bool InitLinkedLeadList(LinkedList* L) {
	*L = (struct LNode*)malloc(sizeof(struct LNode));
	if (*L == NULL) { // �ڴ治��
		return false;
	}
	(*L)->next = NULL;
	return true;
}

// ��λ����루��ͷ�ڵ㣩
bool InsertLinkedList(LinkedList L, int i, int e) {
	if (i < 1) {
		printf("λ�򲻺Ϸ�");
		return false;
	}
	LinkedNode* p = L; // ��pָ�����α���������ʼLָ��ͷ�ڵ㣬����Ϊ0
	int j = 0; // j��¼p�������ǵڼ����ڵ�
	while (p != NULL && j < i - 1) { // ѭ���ҵ���i-1���ڵ�
		p = p->next;
		j++;
	}
	if (p == NULL) {
		printf("λ�򲻺Ϸ�����ǰ����%d", j);
		return false;
	}
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode*));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ��ӡ��ͷ����
void PrintLinkedList(LinkedList L) {
	L = L->next;
	int j = 1;
	while (L){
		printf("%5d%10d\n", j, L->data);
		L = L->next;
		j++;
	}
}