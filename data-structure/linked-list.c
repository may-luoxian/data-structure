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
	LinkedNode* s = (struct LNode*)malloc(sizeof(struct LNode*));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 打印带头链表
void PrintLinkedList(LinkedList L) {
	L = L->next;
	int j = 1;
	while (L){
		printf("%5d%10d\n", j, L->data);
		L = L->next;
		j++;
	}
}