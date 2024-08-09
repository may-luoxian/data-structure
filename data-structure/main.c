#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	LinkedList L;
	InitLinkedLeadList(&L);
	for (int i = 1; i <= 10; i++) {
		InsertLinkedList(L, i, i);
	}
	PrintLinkedList(L);
	return 0;
}