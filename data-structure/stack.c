#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

// 初始化顺序栈
void InitSeqStack(SeqStack* S) {
	S->top = -1;
}

// 进栈操作
bool Push(SeqStack* S, int x) {
	if (S->top == MAX_SIZE - 1) {
		printf("栈满");
		return false;
	}
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}

// 出栈操作
int Pop(SeqStack* S) {
	if (S->top == -1) {
		printf("栈空");
		return -1;
	}
	int e = S->data[S->top];
	/*S->data[S->top] = NULL;*/ // 数据残留，逻辑删除
	S->top = S->top - 1;
	return e;
}

// 读栈顶元素
int GetTop(SeqStack S) {
	if (S.top == -1) {
		printf("栈空");
		return -1;
	}
	return S.data[S.top];
}

// 判断栈空
bool isEmptySeqStack(SeqStack S) {
	return S.top == -1;
}


// 栈的应用
// 括号匹配的应用
bool bracketCheck(char* str, int length) {
	// 初始化栈
	SeqStack S;
	InitSeqStack(&S);

	// 循环遍历括号数组
	for (int i = 0; i < length; i++) {
		// 判断字符是否符合规范
		if (str[i] != '(' && str[i] != '[' && str[i] != '{' && str[i] != ")" && str[i] != "]" && str[i] != "}") {
			printf("字符不符合规范");
			return false;
		}

		if (str[i] == '(' || str[i] == '[' || str[i] == '{') { // 如果是左括号，入栈
			Push(&S, str[i]);
		}
		else { // 如果是右括号，则需要从栈中寻找与之匹配的左括号。
			// 判断栈是否为空，为空直接匹配失败
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
	return isEmptySeqStack(S); // 最终判断栈是否为空
}