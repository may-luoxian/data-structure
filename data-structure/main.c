#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"

int main() {
	char str[] = {'(','q', '(', ')', ')'};
	bool result = bracketCheck(&str, ARRAY_LENGTH(str));
	printf("%d", result);
}