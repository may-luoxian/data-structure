#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 初始化串
bool InitString(SeqString* S) {
	S->length = 0;
	return true;
}

// 打印串
void PrintString(SeqString S) {
	for (int i = 0; i < S.length; i++) {
		printf("%c", S.ch[i]);
	}
}

// 求子串
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

// 比较串大小
int StrCompare(SeqString S, SeqString T) {
	int minLength = S.length > T.length ? T.length : S.length;

	for (int i = 0; i < minLength; i++) {
		if (S.ch[i] != T.ch[i]) {
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}

// 定位操作-1
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