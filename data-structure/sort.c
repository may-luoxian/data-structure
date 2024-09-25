#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"
#include "sort.h"

// 插入排序
void insert_sort(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) // 这个for循环执行n-1轮
	{
		if (arr[i] < arr[i - 1]) // 判断若当前元素小于前一个元素
		{
			temp = arr[i]; // 提取出当前元素
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) // 与这个元素之前的所有元素依次对比，若当前元素小于数组中元素，将数组中元素后移，若大于则插入到j+1位置
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

// 折半插入排序
void binary_insert_sort(int arr[], int n) {
	int i, j, temp, low, high, mid;
	for (i = 1; i < n; i++) // 这个for循环执行n-1轮
	{
		temp = arr[i];
		low = 0;
		high = i - 1;
		// 此时i前所有元素有序，可以采用折半查找，找到最小的比arr[i]大的元素
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (arr[mid] > temp)
			{
				high = mid - 1;
			}
			else // 为保持稳定性，当arr[mid]等于或小于temp时，都需要将low指向mid+1，即要让low指针指向第一个比temp大的元素
			{
				low = mid + 1;
			}
		}

		for (j = i - 1; j >= low; j--) // 让low和low之后，到i之前所有元素后移
		{
			arr[j + 1] = arr[j];
		}
		arr[low] = temp;
	}
}

// 希尔排序
void shell_sort(int arr[], int n) {
	int d, i, j, temp;
	for (d = 4; d >= 1; d = d / 2) // 每次步长减半
	{
		for (i = d; i < n; i++) // 另i等于步长，指向分组第二个元素
		{
			if (arr[i] < arr[i - d]) // 直接插入排序步骤，只是步长为d
			{
				temp = arr[i];
				for (j = i - d; j >= 0 && temp < arr[j]; j = j - d)
				{
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}

// 冒泡排序
void bubble_sort(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
		if (flag == false) {
			return;
		}
	}

}

// 快速排序
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

// 简单选择排序
void select_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (arr[i] != arr[min])
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

// 堆排序
// 将以k为根的子树调整为大根堆
void head_adjust(int arr[], int k, int n) {
	int temp = arr[k];
	for (int i = 2 * k + 1; i < n; i = i * 2 + 1) // i为二叉树的左孩子索引
	{
		if (i + 1 < n && arr[i] < arr[i + 1]) // 判断右孩子是否存在，若存在与左孩子比较大小，i指向较大的孩子
		{
			i++;
		}
		if (temp >= arr[i]) // 比较父节点与最大的孩子，将最大的节点调整到父节点位置
		{
			break; // 若未发生调整，子树符合大根堆
		}
		else // 发生调整后，子树有可能不符合大根堆，继续调整子树
		{
			arr[k] = arr[i];
			k = i; // 使k指向孩子节点，即下一轮需要调整的父节点
		}
	}
	arr[k] = temp;
}

// 初始建立大根堆
void build_max_heap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) // 从后向前调整所有非叶子节点
	{
		head_adjust(arr, i, n);
	}
}

// 堆排序逻辑
void heap_sort(int arr[], int n) {
	build_max_heap(arr, n); // 初始将整棵树调整为大根堆

	for (int i = n; i > 1; i--) // n - 1次调整
	{
		int temp = arr[i - 1]; // 将根节点换到最后
		arr[i - 1] = arr[0];
		arr[0] = temp;

		head_adjust(arr, 0, i - 1); // 调整除最后节点外所有节点为大根堆
	}
}

// 归并排序
void merge(int arr[], int low, int mid, int high, int b[]) {
	int i, j, k;
	for (i = low; i <= high; i++)
	{
		b[i] = arr[i];
	}

	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (b[i] <= b[j])
		{
			arr[k] = b[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
	}
	while (i <= mid)
	{
		arr[k] = b[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		arr[k] = b[j];
		k++;
		j++;
	}
}

void merge_logic(int arr, int low, int high, int b[]) {
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_logic(arr, low, mid, b);
		merge_logic(arr, mid + 1, high, b);
		merge(arr, low, mid, high, b);
	}
}

void merge_sort(int arr[], int n) {
	int low = 0, high = n - 1;
	int* b = (int*)malloc(n * sizeof(int));
	merge_logic(arr, low, high, b);
	free(b);
}