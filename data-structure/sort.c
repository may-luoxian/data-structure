#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"
#include "sort.h"

void quick_sort(int arr[], int low, int high)
{
	int head = low; // 头指针
	int tail = high; // 尾指针
	int key = arr[head]; // 取出基准值

	// 如果头尾指针碰撞，结束循环
	while (head < tail)
	{
		// 尾指针指向元素大于等于基准值时，尾指针依次向前移动
		while (head < tail && arr[tail] >= key)
		{
			tail--;
		}
		// 如果尾指针指向元素小于基准值，将尾指针元素放到空余的头指针位置
		arr[head] = arr[tail];

		// 头指针指向元素小于等于基准值时，头指针依次向后移动
		while (head < tail && arr[head] <= key)
		{
			head++;
		}
		// 如果头指针指向元素大于基准值，将头指针元素放到空余的尾指针位置
		arr[tail] = arr[head];
	}
	// 指针碰撞，此时头尾指针处于同一位置，将基准值放回数组中
	arr[head] = key;

	// 对基准值左右两侧的数据再次进行快速查找（递归）
	if (head - 1 > low)
	{
		quick_sort(arr, low, head - 1);
	}
	if (head + 1 < high)
	{
		quick_sort(arr, head + 1, high);
	}
	return;
}