#pragma once
#define MAX_SIZE 10 // 静态分配最大长度
#define INIT_SIZE 10 // 动态分配初始长度
// 顺序表结构—静态分配
typedef struct SSeqLsit {
	int data[MAX_SIZE]; // 顺序表数据
	int length; // 顺序表长度
} StaticSeqList;

/*
	通过mallic和free函数动态申请和释放空间
*/
// 顺序表结构—动态分配
typedef struct DSeqList {
	int* data; // 动态分配数组指针
	int MaxSize; // 顺序表最大容量
	int length; // 顺序表长度
} DynamicSeqList;

// 单链表
typedef struct LNode {
	int data; // 数据域
	struct LNode* next; // 指针域-指向下一个节点
} LinkedNode, * LinkedList; // LinkedNode用于表示节点，*LinkedList用于表示整个链表的头指针（强调整个链表）

// 双链表
typedef struct DNode {
	int data; // 数据域
	struct DNode *prior, *next; // prior指向前驱，next指向后继
} DoubleNode, * DoubleLinkedList;

// 静态链表-10长度
typedef struct SNode {
	int data; // 数据域
	int next; // 下一个元素的数组下标（游标）
} SLinkedList[MAX_SIZE];