#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 初始化顺序队列
void InitSeqQueue(SeqQueue* Q) {
	Q->rear = Q->front = 0; // 另对头队尾指向0，即要插入第一个元素的位置
}

// 循环队列-入队
bool EnSeqQueue(SeqQueue* Q, int x) {
	if ((Q->rear + 1) % MAX_SIZE == Q->front) {
		printf("队满");
		return false;
	}

	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	return true;
}

// 循环队列-出队
int OutSeqQueue(SeqQueue* Q) {
	if (Q->rear == Q->front) {
		printf("队空");
		return -1;
	}

	int e = Q->data[Q->front];
	/*Q->data[Q->front] = NULL;*/
	Q->front = (Q->front + 1) % MAX_SIZE;
	return e;
}

// 获取对头元素的值
int GetHeadSeqQueue(SeqQueue Q) {
	if (Q.rear == Q.front) {
		printf("队空");
		return -1;
	}
	return Q.data[Q.front];
}

// 查询队列元素个数
int GetSeqQueueLength(SeqQueue Q) {
	return (Q.rear + MAX_SIZE - Q.front) % MAX_SIZE;
}


// 初始化链队列（带头结点）
void InitLinkHeadQueue(LinkQueue* Q) {
	// 令头/尾指针指向头节点
	LQueueNode* p = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (p == NULL) {
		printf("内存不足");
		return;
	}
	Q->front = Q->rear = p;
	Q->front->next = NULL;
}

// 初始化链队列（不带头结点）
void InitLinkQueue(LinkQueue* Q) {
	// 令头/尾指针指向NULL
	Q->front = NULL;
	Q->rear = NULL;
}

// 入队-带头结点
bool EnLinkHeadQueue(LinkQueue* Q, int x) {
	LQueueNode* s = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (s == NULL) {
		printf("内存不足");
		return false;
	}
	s->data = x;
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return true;
}

// 出队-带头结点
int OutLinkHeadQueue(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("队空");
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

// 入队-不带头结点
bool EnLinkQueue(LinkQueue* Q, int x) {
	LQueueNode* s = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (s == NULL) {
		printf("内存不足");
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

// 出队-不带头结点
int OutLinkQueue(LinkQueue* Q) {
	if (Q->front == NULL) {
		printf("队空");
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