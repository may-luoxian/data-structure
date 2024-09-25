#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"
#include "search.h"
#include "sort.h"
#include "sequence.h"


int main() {
	DynamicSeqList seqlist;
	InitDynaticSeqList(&seqlist);
	initValue(&seqlist);

	merge_sort(seqlist.data, seqlist.length);

	PrintDynamicSeqList(seqlist);
}