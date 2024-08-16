#pragma once
#define MAX_SIZE 10 // ��̬������󳤶�
#define INIT_SIZE 10 // ��̬�����ʼ����
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