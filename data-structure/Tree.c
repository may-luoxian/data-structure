#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ��˳��洢������
void InitSeqBinaryTree(SeqBinaryTreeNode t[]) {
	for (int i = 0; i < TREE_SIZE; i++)
	{
		t[i].isEmpty = true;
	}
}

// ��ʼ����������
bool InitLinkBiTree(LinkBiTree* t) {
	(*t) = NULL;
	(*t) = (LinkBiTree) malloc(sizeof(LinkBiTNode)); // ��ʼ�����ڵ�
	if ((*t) == NULL) {
		return false;
	}
	(*t)->data = 0;
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
	return true;
}

// �������Ĳ������--����˼·���޷�ִ��
void LevelOrder(LinkBiTree t) {
	AuxQueue Q;
	InitQueue(); // ��ʼ������
	EnQueue(Q, t); // ��������
	while (!isEmpty(t))
	{
		LinkBiTNode p = Dequeue(Q); // ��ͷ������
		visit(p); // ���ʳ��ӽ��
		// ���p�����Һ��ӷǿգ��������
		if (p.lchild != NULL)
		{
			EnQueue(Q, p.lchild);
		}
		if (p.rchild != NULL)
		{
			EnQueue(Q, p.rchild);
		}
	}
	// ֱ������Ϊ���˳�ѭ��
}

// ��������
// �������������в���Ԫ��
// ������������ڵ�
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

// �����½ڵ㵽����������
LinkBiTNode* InsertLBiTNode(LinkBiTNode* node, int data) {
	if (node == NULL) {
		return CreateLBitNode(data);
	}
	// ���ѡ��������Һ���
	if (rand() % 2) {
		node->lchild = InsertLBiTNode(node->lchild, data);
	}
	else {
		node->rchild = InsertLBiTNode(node->rchild, data);
	}
	return node;
}

// ѭ�������㣬�����
void InsertElements(LinkBiTree* t, int elementNums) {
	for (int i = 0; i < elementNums; i++)
	{
		InsertLBiTNode(*t, i + 1);
	}
}