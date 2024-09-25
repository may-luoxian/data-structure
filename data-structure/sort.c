#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"
#include "sort.h"

// ��������
void insert_sort(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) // ���forѭ��ִ��n-1��
	{
		if (arr[i] < arr[i - 1]) // �ж�����ǰԪ��С��ǰһ��Ԫ��
		{
			temp = arr[i]; // ��ȡ����ǰԪ��
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) // �����Ԫ��֮ǰ������Ԫ�����ζԱȣ�����ǰԪ��С��������Ԫ�أ���������Ԫ�غ��ƣ�����������뵽j+1λ��
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

// �۰��������
void binary_insert_sort(int arr[], int n) {
	int i, j, temp, low, high, mid;
	for (i = 1; i < n; i++) // ���forѭ��ִ��n-1��
	{
		temp = arr[i];
		low = 0;
		high = i - 1;
		// ��ʱiǰ����Ԫ�����򣬿��Բ����۰���ң��ҵ���С�ı�arr[i]���Ԫ��
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (arr[mid] > temp)
			{
				high = mid - 1;
			}
			else // Ϊ�����ȶ��ԣ���arr[mid]���ڻ�С��tempʱ������Ҫ��lowָ��mid+1����Ҫ��lowָ��ָ���һ����temp���Ԫ��
			{
				low = mid + 1;
			}
		}

		for (j = i - 1; j >= low; j--) // ��low��low֮�󣬵�i֮ǰ����Ԫ�غ���
		{
			arr[j + 1] = arr[j];
		}
		arr[low] = temp;
	}
}

// ϣ������
void shell_sort(int arr[], int n) {
	int d, i, j, temp;
	for (d = 4; d >= 1; d = d / 2) // ÿ�β�������
	{
		for (i = d; i < n; i++) // ��i���ڲ�����ָ�����ڶ���Ԫ��
		{
			if (arr[i] < arr[i - d]) // ֱ�Ӳ��������裬ֻ�ǲ���Ϊd
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

// ð������
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

// ��������
void quick_sort(int arr[], int low, int high)
{
	int head = low; // ͷָ��
	int tail = high; // βָ��
	int key = arr[head]; // ȡ����׼ֵ

	// ���ͷβָ����ײ������ѭ��
	while (head < tail)
	{
		// βָ��ָ��Ԫ�ش��ڵ��ڻ�׼ֵʱ��βָ��������ǰ�ƶ�
		while (head < tail && arr[tail] >= key)
		{
			tail--;
		}
		// ���βָ��ָ��Ԫ��С�ڻ�׼ֵ����βָ��Ԫ�طŵ������ͷָ��λ��
		arr[head] = arr[tail];

		// ͷָ��ָ��Ԫ��С�ڵ��ڻ�׼ֵʱ��ͷָ����������ƶ�
		while (head < tail && arr[head] <= key)
		{
			head++;
		}
		// ���ͷָ��ָ��Ԫ�ش��ڻ�׼ֵ����ͷָ��Ԫ�طŵ������βָ��λ��
		arr[tail] = arr[head];
	}
	// ָ����ײ����ʱͷβָ�봦��ͬһλ�ã�����׼ֵ�Ż�������
	arr[head] = key;

	// �Ի�׼ֵ��������������ٴν��п��ٲ��ң��ݹ飩
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

// ��ѡ������
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

// ������
// ����kΪ������������Ϊ�����
void head_adjust(int arr[], int k, int n) {
	int temp = arr[k];
	for (int i = 2 * k + 1; i < n; i = i * 2 + 1) // iΪ����������������
	{
		if (i + 1 < n && arr[i] < arr[i + 1]) // �ж��Һ����Ƿ���ڣ������������ӱȽϴ�С��iָ��ϴ�ĺ���
		{
			i++;
		}
		if (temp >= arr[i]) // �Ƚϸ��ڵ������ĺ��ӣ������Ľڵ���������ڵ�λ��
		{
			break; // ��δ�����������������ϴ����
		}
		else // ���������������п��ܲ����ϴ���ѣ�������������
		{
			arr[k] = arr[i];
			k = i; // ʹkָ���ӽڵ㣬����һ����Ҫ�����ĸ��ڵ�
		}
	}
	arr[k] = temp;
}

// ��ʼ���������
void build_max_heap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) // �Ӻ���ǰ�������з�Ҷ�ӽڵ�
	{
		head_adjust(arr, i, n);
	}
}

// �������߼�
void heap_sort(int arr[], int n) {
	build_max_heap(arr, n); // ��ʼ������������Ϊ�����

	for (int i = n; i > 1; i--) // n - 1�ε���
	{
		int temp = arr[i - 1]; // �����ڵ㻻�����
		arr[i - 1] = arr[0];
		arr[0] = temp;

		head_adjust(arr, 0, i - 1); // ���������ڵ������нڵ�Ϊ�����
	}
}

// �鲢����
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