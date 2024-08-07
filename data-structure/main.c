#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	LinkedList L;
	InitLinkedLeadList(&L);
	InsertLinkedList(L, 1, 10);
	InsertLinkedList(L, 1, 5);
	PrintLinkedList(L);
	return 0;
}