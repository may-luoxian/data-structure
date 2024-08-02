#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "data-type.h"


extern void initList(StaticSeqList*);
extern void printSeqList(StaticSeqList);
int main() {
	/*StaticSeqList seq;
	initList(&seq);
	printSeqList(seq);*/

	DynamicSeqList seq;
	initDynaticList(&seq);
	addData(&seq, 1);
	addData(&seq, 2);
	addData(&seq, 3);
	addData(&seq, 4);
	addData(&seq, 5);
	addData(&seq, 6);
	addData(&seq, 7);
	addData(&seq, 8);
	addData(&seq, 9);
	addData(&seq, 10);
	addData(&seq, 11);
	increaseSize(&seq, 5);
	addData(&seq, 11);
	printDynamicSeqList(seq);
	return 0;
}