#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 初始化顺序存储二叉树
void InitSeqBinaryTree(SeqBinaryTreeNode t[]) {
	for (int i = 0; i < TREE_SIZE; i++)
	{
		t[i].isEmpty = true;
	}
}

// 初始化二叉链表
bool InitLinkBiTree(LinkBiTree* t) {
	(*t) = NULL;
	(*t) = (LinkBiTree) malloc(sizeof(LinkBiTNode)); // 初始化根节点
	if ((*t) == NULL) {
		return false;
	}
	(*t)->data = 0;
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
	return true;
}

// 二叉树的层序遍历--大致思路，无法执行
void LevelOrder(LinkBiTree t) {
	AuxQueue Q;
	InitQueue(); // 初始化队列
	EnQueue(Q, t); // 跟结点入队
	while (!isEmpty(t))
	{
		LinkBiTNode p = Dequeue(Q); // 对头结点出队
		visit(p); // 访问出队结点
		// 如果p的左右孩子非空，依次入队
		if (p.lchild != NULL)
		{
			EnQueue(Q, p.lchild);
		}
		if (p.rchild != NULL)
		{
			EnQueue(Q, p.rchild);
		}
	}
	// 直到队列为空退出循环
}

// 辅助函数
// 随机向二叉链表中插入元素
// 创建二叉链表节点
LinkBiTNode* CreateLBitNode(int data) {
	LinkBiTNode* node = malloc(sizeof(LinkBiTNode));
	if (node == NULL) {
		return NULL;
	}
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

// 插入新节点到二叉链表中
LinkBiTNode* InsertLBiTNode(LinkBiTNode* node, int data) {
	if (node == NULL) {
		return CreateLBitNode(data);
	}
	// 随机选择插入左右孩子
	if (rand() % 2) {
		node->lchild = InsertLBiTNode(node->lchild, data);
	}
	else {
		node->rchild = InsertLBiTNode(node->rchild, data);
	}
	return node;
}

// 循环插入结点，并编号
void InsertElements(LinkBiTree* t, int elementNums) {
	for (int i = 0; i < elementNums; i++)
	{
		InsertLBiTNode(*t, i + 1);
	}
}