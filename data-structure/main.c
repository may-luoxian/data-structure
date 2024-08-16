#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	SeqStack S;
	InitSeqStack(&S);
	Push(&S, 1);

	int x = GetTop(S);
	printf("%d", x);
}