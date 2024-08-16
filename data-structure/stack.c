#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ��˳��ջ
void InitSeqStack(SeqStack* S) {
	S->top = -1;
}

// ��ջ����
bool Push(SeqStack* S, int x) {
	if (S->top == MAX_SIZE - 1) {
		printf("ջ��");
		return false;
	}
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}

// ��ջ����
int Pop(SeqStack* S) {
	if (S->top == -1) {
		printf("ջ��");
		return -1;
	}
	int e = S->data[S->top];
	/*S->data[S->top] = NULL;*/ // ���ݲ������߼�ɾ��
	S->top = S->top - 1;
	return e;
}

// ��ջ��Ԫ��
int GetTop(SeqStack S) {
	if (S.top == -1) {
		printf("ջ��");
		return -1;
	}
	return S.data[S.top];
}

// �ж�ջ��
bool isEmptySeqStack(SeqStack S) {
	return S.top == -1;
}


// ջ��Ӧ��
// ����ƥ���Ӧ��
bool bracketCheck(char* str, int length) {
	// ��ʼ��ջ
	SeqStack S;
	InitSeqStack(&S);

	// ѭ��������������
	for (int i = 0; i < length; i++) {
		// �ж��ַ��Ƿ���Ϲ淶
		if (str[i] != '(' && str[i] != '[' && str[i] != '{' && str[i] != ")" && str[i] != "]" && str[i] != "}") {
			printf("�ַ������Ϲ淶");
			return false;
		}

		if (str[i] == '(' || str[i] == '[' || str[i] == '{') { // ����������ţ���ջ
			Push(&S, str[i]);
		}
		else { // ����������ţ�����Ҫ��ջ��Ѱ����֮ƥ��������š�
			// �ж�ջ�Ƿ�Ϊ�գ�Ϊ��ֱ��ƥ��ʧ��
			if (isEmptySeqStack(S)) {
				return false;
			}
			char topElem = Pop(&S);
			if (str[i] == ")" && topElem != "(") {
				return false;
			}
			if (str[i] == "]" && topElem != "[") {
				return false;
			}
			if (str[i] == "}" && topElem != "{") {
				return false;
			}
		}
	}
	return isEmptySeqStack(S); // �����ж�ջ�Ƿ�Ϊ��
}