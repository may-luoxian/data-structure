#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ��˳�����
void InitSeqQueue(SeqQueue* Q) {
	Q->rear = Q->front = 0; // ���ͷ��βָ��0����Ҫ�����һ��Ԫ�ص�λ��
}

// ѭ������-���
bool EnSeqQueue(SeqQueue* Q, int x) {
	if ((Q->rear + 1) % MAX_SIZE == Q->front) {
		printf("����");
		return false;
	}

	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	return true;
}

// ѭ������-����
int OutSeqQueue(SeqQueue* Q) {
	if (Q->rear == Q->front) {
		printf("�ӿ�");
		return -1;
	}

	int e = Q->data[Q->front];
	/*Q->data[Q->front] = NULL;*/
	Q->front = (Q->front + 1) % MAX_SIZE;
	return e;
}

// ��ȡ��ͷԪ�ص�ֵ
int GetHeadSeqQueue(SeqQueue Q) {
	if (Q.rear == Q.front) {
		printf("�ӿ�");
		return -1;
	}
	return Q.data[Q.front];
}

// ��ѯ����Ԫ�ظ���
int GetSeqQueueLength(SeqQueue Q) {
	return (Q.rear + MAX_SIZE - Q.front) % MAX_SIZE;
}


// ��ʼ�������У���ͷ��㣩
void InitLinkHeadQueue(LinkQueue* Q) {
	// ��ͷ/βָ��ָ��ͷ�ڵ�
	LQueueNode* p = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (p == NULL) {
		printf("�ڴ治��");
		return;
	}
	Q->front = Q->rear = p;
	Q->front->next = NULL;
}

// ��ʼ�������У�����ͷ��㣩
void InitLinkQueue(LinkQueue* Q) {
	// ��ͷ/βָ��ָ��NULL
	Q->front = NULL;
	Q->rear = NULL;
}

// ���-��ͷ���
bool EnLinkHeadQueue(LinkQueue* Q, int x) {
	LQueueNode* s = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (s == NULL) {
		printf("�ڴ治��");
		return false;
	}
	s->data = x;
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return true;
}

// ����-��ͷ���
int OutLinkHeadQueue(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("�ӿ�");
		return -1;
	}
	LQueueNode* p = Q->front->next;
	int x = p->data;
	Q->front->next = p->next;
	if (Q->rear = p) {
		Q->rear = Q->front;
	}
	free(p);
	return x;
}

// ���-����ͷ���
bool EnLinkQueue(LinkQueue* Q, int x) {
	LQueueNode* s = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (s == NULL) {
		printf("�ڴ治��");
		return false;
	}
	s->data = x;
	s->next = NULL;
	if (Q->front = NULL) {
		Q->front = s;
		Q->rear = s;
	}
	else {
		Q->rear->next = s;
		Q->rear = s;
	}
	return true;
}

// ����-����ͷ���
int OutLinkQueue(LinkQueue* Q) {
	if (Q->front == NULL) {
		printf("�ӿ�");
		return -1;
	}
	LQueueNode* p = Q->front;
	int x = p->data;
	Q->front = p->next;
	if (Q->rear == p) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	free(p);
	return x;
}