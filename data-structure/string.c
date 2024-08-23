#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// ��ʼ����
bool InitString(SeqString* S) {
	S->length = 0;
	return true;
}

// ��ӡ��
void PrintString(SeqString S) {
	for (int i = 0; i < S.length; i++) {
		printf("%c", S.ch[i]);
	}
}

// ���Ӵ�
bool SubString(SeqString* Sub, SeqString S, int pos, int len) {
	if (pos + len > S.length) {
		return false;
	}
	for (int i = pos + 1; i <= pos + len; i++) {
		Sub->ch[i - pos - 1] = S.ch[i - 1];
	}
	Sub->length = len;
	return true;
}

// �Ƚϴ���С
int StrCompare(SeqString S, SeqString T) {
	int minLength = S.length > T.length ? T.length : S.length;

	for (int i = 0; i < minLength; i++) {
		if (S.ch[i] != T.ch[i]) {
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}

// ��λ����-1
int StrIndex(SeqString S, SeqString T) {
	int i = 0, n = S.length, m = T.length;
	SeqString sub;
	while (i <= n - m) {
		SubString(&sub, S, i, m);
		int isEqual = StrCompare(sub, T);
		if (isEqual != 0) {
			i++;
		}
		else {
			return i;
		}
	}
	return 0;
}

// ����ģʽƥ���㷨
int MatchAlgorithm(SeqString S, SeqString T) {
	int i = 0, j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}

	if (j >= T.length) {
		return i - T.length;
	}
	return 0;
}

// KMP�㷨
// KMP�㷨ģʽƥ�䲿��
int Index_KMP(SeqString S, SeqString T, int next[]) {
	int i = 0, j = 0;

	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else if (S.ch[i] != T.ch[j] && j == 0) {
			i++;
		}
		else {
			j = next[j];
		}
	}

	if (j >= T.length) {
		return i - T.length;
	}
	return 0;
}

// KMP�㷨next���鲿�֡������