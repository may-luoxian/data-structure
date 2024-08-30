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
bool InitLinkBiTree(CBiTree* t) {
	(*t) = NULL;
	(*t) = (CBiTree) malloc(sizeof(CBitNode)); // 初始化根节点
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

// 二叉树的层序遍历--大致思路，无法执行
//void LevelOrder(LinkBiTree t) {
//	AuxQueue Q;
//	InitQueue(); // 初始化队列
//	EnQueue(Q, t); // 跟结点入队
//	while (!isEmpty(t))
//	{
//		LinkBiTNode p = Dequeue(Q); // 对头结点出队
//		visit(p); // 访问出队结点
//		// 如果p的左右孩子非空，依次入队
//		if (p.lchild != NULL)
//		{
//			EnQueue(Q, p.lchild);
//		}
//		if (p.rchild != NULL)
//		{
//			EnQueue(Q, p.rchild);
//		}
//	}
//	// 直到队列为空退出循环
//}

/*
	1.输出二叉树结点
	2.二叉树线索化
*/
CBitNode* pre; // 指向当前访问节点前驱

// 打印并线索化结点
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


// 线索二叉树遍历
void CInOrder(CBiTree T) {
	if (T != NULL) {
		// 中序遍历
		CInOrder(T->lchild);
		PrintCBiTNode(T);
		CInOrder(T->rchild);

		// 先序遍历
		//PrintCBiTNode(T);
		//if (T->ltag == 0) { // 在print中改变了叶子节点孩子指针为线索，为防止无限循环，需要判断ltag是否为线索
		//	CInOrder(T->lchild);
		//}
		//CInOrder(T->rchild);

		// 后序遍历
		/*CInOrder(T->lchild);
		CInOrder(T->rchild);
		PrintCBiTNode(T);*/
	}
}

/*
	二叉树线索化
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

// 辅助函数
// 随机向二叉链表中插入元素
// 创建二叉链表节点
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

// 插入新节点到二叉链表中
CBitNode* InsertLBiTNode(CBitNode* node, int data) {
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
void InsertElements(CBiTree* t, int elementNums) {
	for (int i = 0; i < elementNums; i++)
	{
		InsertLBiTNode(*t, i + 1);
	}
}