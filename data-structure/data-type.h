#pragma once
#define MAX_SIZE 10 // 静态分配最大长度
#define INIT_SIZE 10 // 动态分配初始长度
#define STRING_SIZE 255 // 串的最大长度
#define TREE_SIZE 100 // 树的最大长度
#define MAX_VERTEM_NUM 100 // 图的顶点数目

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
	struct DNode* prior, * next; // prior指向前驱，next指向后继
} DoubleNode, * DoubleLinkedList;

// 静态链表-10长度
typedef struct SNode {
	int data; // 数据域
	int next; // 下一个元素的数组下标（游标）
} SLinkedList[MAX_SIZE];

// 顺序栈-10长度
typedef struct SStack {
	int data[MAX_SIZE]; // 静态数组存放栈中元素
	int top; // 栈顶指针
} SeqStack;

// 链栈
typedef struct LStackNode {
	int data;
	struct LStackNode* next;
} *LinkStack;

// 顺序队列
typedef struct {
	int data[MAX_SIZE]; // 用静态数组存放队列元素
	int front, rear; // 对头指针和队尾指针
} SeqQueue;

// 链式队列
typedef struct LQNode {  // 链式队列的结点
	int data;
	struct LQueueNode* next;
} LQueueNode;

typedef struct { // 指向队头队尾的指针
	LQueueNode* front, * rear;
} LinkQueue;

// 串的顺序存储-定长顺序存储
typedef struct {
	char ch[STRING_SIZE];
	int length;
} SeqString;

// 串的顺序存储-变长顺序存储
typedef struct {
	char* ch;
	int length;
} HString;

// 串的链式存储
typedef struct StringNode {
	char ch;
	struct StringNode* next;
} StringNode, * LinkString;

// 二叉树的顺序存储
typedef struct SeqBinaryTreeNode {
	int value; // 结点中的数据元素
	bool isEmpty; // 结点是否为空
} SeqBinaryTreeNode;

// 二叉树的链式存储结构
typedef struct LinkBinaryTreeNode {
	int data; // 数据域
	struct LinkBinaryTreeNode* lchild, * rchild; // 左右孩子指针
} LinkBiTNode, *LinkBiTree;

// 二叉链表层序遍历辅助队列
typedef struct AuxQueueNode {
	LinkBiTNode* node; // 此处存储指向结点的指针
	struct AuxQueueNode* next;
} AuxQueueNode;

typedef struct {
	AuxQueueNode* front, * rear;
} AuxQueue;

// 线索二叉树
typedef struct ClueBiTNode {
	int data;
	struct ClueBiTNode* lchild, * rchild;
	int ltag, rtag; // 左、右线索标志，0指向孩子，1指向线索
} CBitNode, *CBiTree;

// 图的邻接矩阵存储
typedef struct {
	char vex[MAX_VERTEM_NUM]; // 顶点表
	int edge[MAX_VERTEM_NUM][MAX_VERTEM_NUM]; // 邻接矩阵，边表
	int vexnum, arcnum; // 图的当前顶点数和边数/弧数
} MGraph;

// 图的邻接表存储
// 边以链表方式存储
typedef struct ArcNode {
	int adjvex; // 边/弧指向哪个结点
	struct ArcNode* next; // 指向下一边或弧的指针
	// 边权值
} ArcNode;

// 顶点以顺序数组方式存储
typedef struct VNode {
	char vex; // 顶点信息
	ArcNode* first; // 指向第一个边/弧
}VNode, AdjList[MAX_VERTEM_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum; // 图的当前顶点数和边数/弧数
} AlGraph;




