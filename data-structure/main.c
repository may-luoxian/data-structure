#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	SLinkedList L;
	InitSLinked(&L);
	PrintSLinked(L);
	return 0;
}