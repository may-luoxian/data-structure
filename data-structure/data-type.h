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
} LinkedNode, *LinkedList; // LinkedNode���ڱ�ʾ�ڵ㣬*LinkedList���ڱ�ʾ���������ͷָ�루ǿ����������