#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	SeqString S;
	InitString(&S);
	strcpy(S.ch, "abcdefgh");
	S.length = 8;
	SeqString T;
	InitString(&T);
	strcpy(T.ch, "fgh");
	T.length = 3;
	int result = MatchAlgorithm(S, T);
}