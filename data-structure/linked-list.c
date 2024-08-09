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
	if (s == NULL) {
		printf("�ڴ����ʧ��");
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ָ����������
bool InsertLinkedNextNode(LinkedNode* p, int e) {
	if (p == NULL) {
		printf("������δ�ҵ����");
		return false;
	}
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode*));
	if (s == NULL) {
		printf("�ڴ����ʧ��");
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ָ�����ǰ�����
bool InsertLinkedPriorNode(LinkedNode* p, int e) {
	if (p == NULL) {
		printf("������δ�ҵ����");
		return false;
	}
	LinkedNode* s = (struct LNode*) malloc(sizeof(struct LNode));
	if (s == NULL) {
		printf("�ڴ����ʧ��");
		return false;
	}
	s->next = p->next; // ���´����Ľ�㵱��p���
	s->data = p->data;

	p->data = e; // ԭ����p����Ϊp����ǰ��
	p->next = s;
	return true;
}

// ��λ��ɾ��
int DeleteLinkedList(LinkedList L, int i) {
	if (i < 1) {
		printf("λ�򲻺Ϸ�");
		return -1;
	}
	LinkedNode* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) { // �ҵ�i-1�����
		p = p->next;
		j++;
	}
	if (p == NULL) {
		printf("λ�򲻺Ϸ�����ǰ����%d", j);
		return -1;
	}
	if (p->next == NULL) {
		printf("��ǰ����޺�̽��");
		return -1;
	}
	LinkedNode* q = p->next;
	int e = q->data;

	p->next = q->next; // pָ��ɾ�������¸����
	free(q); // �ͷ�q�ڴ�
	return e;
}

// ָ�����ɾ��
bool DeleteLinkedNode(LinkedNode* p) {
	if (p == NULL) {
		printf("��㲻����");
		return false;
	}
	if (p->next == NULL) {
		printf("pΪ���һ����㣬��������");
		return false;
	}
	LinkedNode* q = p->next;
	p->data = q->data; // �˴������⣬���p�����һ����㣬q.data�ǿ�ָ�롣�����������Ҫ����������ͷ��ʼ��������ɾ��p��㡣
	p->next = q->next;
	free(q);
	return true;
}

// ��λ����
LinkedNode* GetLinkedElem(LinkedList L, int i) {
	if (i < 0) {
		printf("λ�򲻺Ϸ�");
		return NULL;
	}
	LinkedNode* p = L; // ��pָ�����α���������ʼLָ��ͷ�ڵ㣬����Ϊ0
	int j = 0; // j��¼p�������ǵڼ����ڵ�
	while (p != NULL && j < i - 1) { // ѭ���ҵ���i-1���ڵ�
		p = p->next;
		j++;
	}
	return p;
}

// ��ֵ����
LinkedNode* LocateLinkedElem(LinkedList L, int e) {
	LinkedNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

// ���
int LinkedLength(LinkedList L) {
	int len = 0;
	LinkedNode* p = L;
	while (p->next != NULL) 
	{
		p = p->next;
		len++;
	}
	return len;
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