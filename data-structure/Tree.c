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
bool InitLinkBiTree(CBiTree* t) {
	(*t) = NULL;
	(*t) = (CBiTree) malloc(sizeof(CBitNode)); // ��ʼ�����ڵ�
	if ((*t) == NULL) {
		return false;
	}
	(*t)->data = 0;
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
	(*t)->ltag = 0;
	(*t)->rtag = 0;
	return true;
}

// �������Ĳ������--����˼·���޷�ִ��
//void LevelOrder(LinkBiTree t) {
//	AuxQueue Q;
//	InitQueue(); // ��ʼ������
//	EnQueue(Q, t); // ��������
//	while (!isEmpty(t))
//	{
//		LinkBiTNode p = Dequeue(Q); // ��ͷ������
//		visit(p); // ���ʳ��ӽ��
//		// ���p�����Һ��ӷǿգ��������
//		if (p.lchild != NULL)
//		{
//			EnQueue(Q, p.lchild);
//		}
//		if (p.rchild != NULL)
//		{
//			EnQueue(Q, p.rchild);
//		}
//	}
//	// ֱ������Ϊ���˳�ѭ��
//}

/*
	1.������������
	2.������������
*/
CBitNode* pre; // ָ��ǰ���ʽڵ�ǰ��

// ��ӡ�����������
void PrintCBiTNode(CBitNode* q) {
	printf("%d\t", q->data);
	if (q->lchild == NULL) {
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}


// ��������������
void CInOrder(CBiTree T) {
	if (T != NULL) {
		// �������
		CInOrder(T->lchild);
		PrintCBiTNode(T);
		CInOrder(T->rchild);

		// �������
		//PrintCBiTNode(T);
		//if (T->ltag == 0) { // ��print�иı���Ҷ�ӽڵ㺢��ָ��Ϊ������Ϊ��ֹ����ѭ������Ҫ�ж�ltag�Ƿ�Ϊ����
		//	CInOrder(T->lchild);
		//}
		//CInOrder(T->rchild);

		// �������
		/*CInOrder(T->lchild);
		CInOrder(T->rchild);
		PrintCBiTNode(T);*/
	}
}

/*
	������������
*/
void CreateInThread(CBiTree T) {
	pre = NULL;
	if (T == NULL) {
		return;
	}
	CInOrder(T);
	if (pre->rchild = NULL) {
		pre->rtag = 1;
	}
	
}

// ��������
// �������������в���Ԫ��
// ������������ڵ�
CBitNode* CreateLBitNode(int data) {
	CBitNode* node = malloc(sizeof(CBitNode));
	if (node == NULL) {
		return NULL;
	}
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	node->ltag = 0;
	node->rtag = 0;
	return node;
}

// �����½ڵ㵽����������
CBitNode* InsertLBiTNode(CBitNode* node, int data) {
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
void InsertElements(CBiTree* t, int elementNums) {
	for (int i = 0; i < elementNums; i++)
	{
		InsertLBiTNode(*t, i + 1);
	}
}