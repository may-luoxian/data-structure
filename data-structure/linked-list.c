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
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
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
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
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
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
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
	LinkedNode* p; // ��pָ�����α���������ʼLָ��ͷ�ڵ㣬����Ϊ0
	int j = 0; // j��¼p�������ǵڼ����ڵ�
	p = L;
	while (p != NULL && j < i) { // ѭ���ҵ���i-1���ڵ�
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

// β�巨����������
LinkedList TailInsertLinked(LinkedList* L) {
	int x;
	(*L) = (LinkedList*)malloc(sizeof(LinkedNode));
	if ((*L) == NULL) {
		printf("�ڴ治��");
		return NULL;
	}
	(*L)->next = NULL;
	LinkedNode* s;
	LinkedNode* r = (*L); // rΪ��βָ��
	printf("�������������ݣ�");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkedNode*)malloc(sizeof(LinkedNode));
		if (s == NULL) {
			printf("�ڴ治��");
			break;
		}
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s; // rָ���β�½��
		printf("�������������ݣ�");
		scanf("%d", &x);
	}
	r->next = NULL;
	return (*L);
}

// ͷ�巨����������
LinkedList HeadInsertLinked(LinkedList* L) {
	int x;
	(*L) = (LinkedList*)malloc(sizeof(LinkedNode));
	if ((*L) == NULL) {
		printf("�ڴ治��");
		return NULL;
	}
	(*L)->next = NULL;
	LinkedNode* s;
	printf("�������������ݣ�");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkedNode*)malloc(sizeof(LinkedNode));
		if (s == NULL) {
			printf("�ڴ治��");
			break;
		}
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("�������������ݣ�");
		scanf("%d", &x);
	}
	return (*L);
}

// ��ӡ��ͷ������
void PrintLinkedList(LinkedList L) {
	L = L->next;
	int j = 1;
	while (L) {
		printf("%5d%10d\n", j, L->data);
		L = L->next;
		j++;
	}
}


// ��ʼ��˫����
bool InitDoubleLinkedLeadList(DoubleLinkedList* L) {
	(*L) = (DoubleLinkedList*)malloc(sizeof(DoubleNode));
	if ((*L) == NULL) {
		return false;
	}
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return true;
}

// ˫������
bool InsertDoubleLinkedNextNode(DoubleNode* p, int e) {
	DoubleNode* s = (DoubleNode*)malloc(sizeof(DoubleNode));

	if (s == NULL) {
		return false;
	}

	s->data = e;
	s->prior = p;

	if (p->next != NULL) { // ���p���ں�̽�㣬p��Ϊ���һ�����
		p->next->prior = s;
	}

	s->next = p->next;
	p->next = s;
}

// ˫����ɾ��ָ������̽��
bool DeleteDoubleLinked(DoubleNode* p) {
	if (p == NULL) {
		return false;
	}

	DoubleNode* q = p->next;
	if (q == NULL) {
		return false;
	}

	p->next = q->next;

	if (q->next != NULL) { // ���q�������һ�����
		q->next->prior = p;
	}

	free(q);
	return true;
}

// ѭ���ͷŸ��ڵ�
bool DestroyDoubleLinked(DoubleLinkedList* L) {
	while ((*L)->next != NULL) {
		DeleteDoubleLinked(*L);
	}
	free(*L);
	L = NULL;
}


// ��ʼ��ѭ��������-��ͷ���
bool InitLoopLinkedLead(LinkedList* L) {
	*L = (struct LNode*)malloc(sizeof(struct LNode));
	if (*L == NULL) { // �ڴ治��
		return false;
	}
	(*L)->next = (*L);
	return true;
}

// �ж�ѭ���������Ƿ�Ϊ��
bool isEmptyLoopLinked(LinkedList L) {
	return L->next == L;
}

// ��ʼ��ѭ��˫����
bool InitLoopDoubleLinked(DoubleLinkedList* L) {
	(*L) = (DoubleLinkedList*)malloc(sizeof(DoubleNode));
	if ((*L) == NULL) {
		return false;
	}
	(*L)->next = (*L);
	(*L)->prior = (*L);
	return true;
}

// ѭ��˫�����п�ͬѭ�������� ��

// ѭ��˫����Ĳ��롢ɾ��ͬ˫����������Ҫ���ж�β���Ϊ�� ��

// ��̬�����ʼ��
bool InitSLinked(SLinkedList* L) {
	int length = sizeof(SLinkedList) / sizeof(struct SNode);
	struct SNode* p;
	p = (*L);
	p->next = -1;
	for (int i = 1; i < length; i++) {
		p = (*L) + i;
		p->next = -2;
	}
	return true;
}

// ����ĳ��λ��Ľ��

// ��ӡ��̬����
void PrintSLinked(SLinkedList L) {
	int length = sizeof(SLinkedList) / sizeof(struct SNode);
	struct SNode p;
	for (int i = 0; i < length; i++) {
		p = *(L + i);
		printf("%d\t%d\t%d\n", i, p.data, p.next);
	}
}