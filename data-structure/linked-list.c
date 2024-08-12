#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 初始化单链表-不带头节点
bool InitLinkedList(LinkedList* L) {
	*L = NULL;
	return true;
}

// 初始化单链表-带头节点
bool InitLinkedLeadList(LinkedList* L) {
	*L = (struct LNode*)malloc(sizeof(struct LNode));
	if (*L == NULL) { // 内存不足
		return false;
	}
	(*L)->next = NULL;
	return true;
}

// 按位序插入（带头节点）
bool InsertLinkedList(LinkedList L, int i, int e) {
	if (i < 1) {
		printf("位序不合法");
		return false;
	}
	LinkedNode* p = L; // 用p指针依次遍历链表，初始L指向头节点，索引为0
	int j = 0; // j记录p遍历的是第几个节点
	while (p != NULL && j < i - 1) { // 循环找到第i-1个节点
		p = p->next;
		j++;
	}
	if (p == NULL) {
		printf("位序不合法，当前链表长%d", j);
		return false;
	}
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
	if (s == NULL) {
		printf("内存分配失败");
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 指定结点后插操作
bool InsertLinkedNextNode(LinkedNode* p, int e) {
	if (p == NULL) {
		printf("链表中未找到结点");
		return false;
	}
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
	if (s == NULL) {
		printf("内存分配失败");
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 指定结点前插操作
bool InsertLinkedPriorNode(LinkedNode* p, int e) {
	if (p == NULL) {
		printf("链表中未找到结点");
		return false;
	}
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode));
	if (s == NULL) {
		printf("内存分配失败");
		return false;
	}
	s->next = p->next; // 把新创建的结点当作p结点
	s->data = p->data;

	p->data = e; // 原来的p结点改为p结点的前驱
	p->next = s;
	return true;
}

// 按位序删除
int DeleteLinkedList(LinkedList L, int i) {
	if (i < 1) {
		printf("位序不合法");
		return -1;
	}
	LinkedNode* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) { // 找到i-1个结点
		p = p->next;
		j++;
	}
	if (p == NULL) {
		printf("位序不合法，当前链表长%d", j);
		return -1;
	}
	if (p->next == NULL) {
		printf("当前结点无后继结点");
		return -1;
	}
	LinkedNode* q = p->next;
	int e = q->data;

	p->next = q->next; // p指向删除结点的下个结点
	free(q); // 释放q内存
	return e;
}

// 指定结点删除
bool DeleteLinkedNode(LinkedNode* p) {
	if (p == NULL) {
		printf("结点不存在");
		return false;
	}
	if (p->next == NULL) {
		printf("p为最后一个结点，遗留问题");
		return false;
	}
	LinkedNode* q = p->next;
	p->data = q->data; // 此处有问题，如果p是最后一个结点，q.data是空指针。这种情况下需要接收链表，从头开始遍历，再删除p结点。
	p->next = q->next;
	free(q);
	return true;
}

// 按位查找
LinkedNode* GetLinkedElem(LinkedList L, int i) {
	if (i < 0) {
		printf("位序不合法");
		return NULL;
	}
	LinkedNode* p; // 用p指针依次遍历链表，初始L指向头节点，索引为0
	int j = 0; // j记录p遍历的是第几个节点
	p = L;
	while (p != NULL && j < i) { // 循环找到第i-1个节点
		p = p->next;
		j++;
	}
	return p;
}

// 按值查找
LinkedNode* LocateLinkedElem(LinkedList L, int e) {
	LinkedNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

// 求表长
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

// 尾插法建立单链表
LinkedList TailInsertLinked(LinkedList* L) {
	int x;
	(*L) = (LinkedList*)malloc(sizeof(LinkedNode));
	if ((*L) == NULL) {
		printf("内存不足");
		return NULL;
	}
	(*L)->next = NULL;
	LinkedNode* s;
	LinkedNode* r = (*L); // r为表尾指针
	printf("请输入链表数据：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkedNode*)malloc(sizeof(LinkedNode));
		if (s == NULL) {
			printf("内存不足");
			break;
		}
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s; // r指向表尾新结点
		printf("请输入链表数据：");
		scanf("%d", &x);
	}
	r->next = NULL;
	return (*L);
}

// 头插法建立单链表
LinkedList HeadInsertLinked(LinkedList* L) {
	int x;
	(*L) = (LinkedList*)malloc(sizeof(LinkedNode));
	if ((*L) == NULL) {
		printf("内存不足");
		return NULL;
	}
	(*L)->next = NULL;
	LinkedNode* s;
	printf("请输入链表数据：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkedNode*)malloc(sizeof(LinkedNode));
		if (s == NULL) {
			printf("内存不足");
			break;
		}
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("请输入链表数据：");
		scanf("%d", &x);
	}
	return (*L);
}

// 打印带头单链表
void PrintLinkedList(LinkedList L) {
	L = L->next;
	int j = 1;
	while (L) {
		printf("%5d%10d\n", j, L->data);
		L = L->next;
		j++;
	}
}


// 初始化双链表
bool InitDoubleLinkedLeadList(DoubleLinkedList* L) {
	(*L) = (DoubleLinkedList*)malloc(sizeof(DoubleNode));
	if ((*L) == NULL) {
		return false;
	}
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return true;
}

// 双链表后插
bool InsertDoubleLinkedNextNode(DoubleNode* p, int e) {
	DoubleNode* s = (DoubleNode*)malloc(sizeof(DoubleNode));

	if (s == NULL) {
		return false;
	}

	s->data = e;
	s->prior = p;

	if (p->next != NULL) { // 如果p存在后继结点，p不为最后一个结点
		p->next->prior = s;
	}

	s->next = p->next;
	p->next = s;
}

// 双链表删除指定结点后继结点
bool DeleteDoubleLinked(DoubleNode* p) {
	if (p == NULL) {
		return false;
	}

	DoubleNode* q = p->next;
	if (q == NULL) {
		return false;
	}

	p->next = q->next;

	if (q->next != NULL) { // 如果q不是最后一个结点
		q->next->prior = p;
	}

	free(q);
	return true;
}

// 循环释放各节点
bool DestroyDoubleLinked(DoubleLinkedList* L) {
	while ((*L)->next != NULL) {
		DeleteDoubleLinked(*L);
	}
	free(*L);
	L = NULL;
}


// 初始化循环单链表-带头结点
bool InitLoopLinkedLead(LinkedList* L) {
	*L = (struct LNode*)malloc(sizeof(struct LNode));
	if (*L == NULL) { // 内存不足
		return false;
	}
	(*L)->next = (*L);
	return true;
}

// 判断循环单链表是否为空
bool isEmptyLoopLinked(LinkedList L) {
	return L->next == L;
}

// 初始化循环双链表
bool InitLoopDoubleLinked(DoubleLinkedList* L) {
	(*L) = (DoubleLinkedList*)malloc(sizeof(DoubleNode));
	if ((*L) == NULL) {
		return false;
	}
	(*L)->next = (*L);
	(*L)->prior = (*L);
	return true;
}

// 循环双链表判空同循环单链表 略

// 循环双链表的插入、删除同双链表，但不需要再判断尾结点为空 略

// 静态链表初始化
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

// 查找某个位序的结点

// 打印静态链表
void PrintSLinked(SLinkedList L) {
	int length = sizeof(SLinkedList) / sizeof(struct SNode);
	struct SNode p;
	for (int i = 0; i < length; i++) {
		p = *(L + i);
		printf("%d\t%d\t%d\n", i, p.data, p.next);
	}
}