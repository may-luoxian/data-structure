#pragma once
#define MAX_SIZE 10 // ��̬������󳤶�
#define INIT_SIZE 10 // ��̬�����ʼ����
#define STRING_SIZE 255 // ������󳤶�
#define TREE_SIZE 100 // ������󳤶�
#define MAX_VERTEM_NUM 100 // ͼ�Ķ�����Ŀ

// ˳���ṹ����̬����
typedef struct SSeqLsit {
	int data[MAX_SIZE]; // ˳�������
	int length; // ˳�����
} StaticSeqList;

/*
	ͨ��mallic��free������̬������ͷſռ�
*/
// ˳���ṹ����̬����
typedef struct DSeqList {
	int* data; // ��̬��������ָ��
	int MaxSize; // ˳����������
	int length; // ˳�����
} DynamicSeqList;

// ������
typedef struct LNode {
	int data; // ������
	struct LNode* next; // ָ����-ָ����һ���ڵ�
} LinkedNode, * LinkedList; // LinkedNode���ڱ�ʾ�ڵ㣬*LinkedList���ڱ�ʾ���������ͷָ�루ǿ����������

// ˫����
typedef struct DNode {
	int data; // ������
	struct DNode* prior, * next; // priorָ��ǰ����nextָ����
} DoubleNode, * DoubleLinkedList;

// ��̬����-10����
typedef struct SNode {
	int data; // ������
	int next; // ��һ��Ԫ�ص������±꣨�α꣩
} SLinkedList[MAX_SIZE];

// ˳��ջ-10����
typedef struct SStack {
	int data[MAX_SIZE]; // ��̬������ջ��Ԫ��
	int top; // ջ��ָ��
} SeqStack;

// ��ջ
typedef struct LStackNode {
	int data;
	struct LStackNode* next;
} *LinkStack;

// ˳�����
typedef struct {
	int data[MAX_SIZE]; // �þ�̬�����Ŷ���Ԫ��
	int front, rear; // ��ͷָ��Ͷ�βָ��
} SeqQueue;

// ��ʽ����
typedef struct LQNode {  // ��ʽ���еĽ��
	int data;
	struct LQueueNode* next;
} LQueueNode;

typedef struct { // ָ���ͷ��β��ָ��
	LQueueNode* front, * rear;
} LinkQueue;

// ����˳��洢-����˳��洢
typedef struct {
	char ch[STRING_SIZE];
	int length;
} SeqString;

// ����˳��洢-�䳤˳��洢
typedef struct {
	char* ch;
	int length;
} HString;

// ������ʽ�洢
typedef struct StringNode {
	char ch;
	struct StringNode* next;
} StringNode, * LinkString;

// ��������˳��洢
typedef struct SeqBinaryTreeNode {
	int value; // ����е�����Ԫ��
	bool isEmpty; // ����Ƿ�Ϊ��
} SeqBinaryTreeNode;

// ����������ʽ�洢�ṹ
typedef struct LinkBinaryTreeNode {
	int data; // ������
	struct LinkBinaryTreeNode* lchild, * rchild; // ���Һ���ָ��
} LinkBiTNode, *LinkBiTree;

// ����������������������
typedef struct AuxQueueNode {
	LinkBiTNode* node; // �˴��洢ָ�����ָ��
	struct AuxQueueNode* next;
} AuxQueueNode;

typedef struct {
	AuxQueueNode* front, * rear;
} AuxQueue;

// ����������
typedef struct ClueBiTNode {
	int data;
	struct ClueBiTNode* lchild, * rchild;
	int ltag, rtag; // ����������־��0ָ���ӣ�1ָ������
} CBitNode, *CBiTree;

// ͼ���ڽӾ���洢
typedef struct {
	char vex[MAX_VERTEM_NUM]; // �����
	int edge[MAX_VERTEM_NUM][MAX_VERTEM_NUM]; // �ڽӾ��󣬱߱�
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͱ���/����
} MGraph;

// ͼ���ڽӱ�洢
// ��������ʽ�洢
typedef struct ArcNode {
	int adjvex; // ��/��ָ���ĸ����
	struct ArcNode* next; // ָ����һ�߻򻡵�ָ��
	// ��Ȩֵ
} ArcNode;

// ������˳�����鷽ʽ�洢
typedef struct VNode {
	char vex; // ������Ϣ
	ArcNode* first; // ָ���һ����/��
}VNode, AdjList[MAX_VERTEM_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͱ���/����
} AlGraph;




