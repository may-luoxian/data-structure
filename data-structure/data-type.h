#pragma once
#define MAX_SIZE 10 // ��̬������󳤶�
#define INIT_SIZE 10 // ��̬�����ʼ����
// ˳���ṹ����̬����
typedef struct {
	int data[MAX_SIZE]; // ˳�������
	int length; // ˳�����
} StaticSeqList;

/*
	ͨ��mallic��free������̬������ͷſռ�
*/
// ˳���ṹ����̬����
typedef struct {
	int* data; // ��̬��������ָ��
	int MaxSize; // ˳����������
	int length; // ˳�����
} DynamicSeqList;

