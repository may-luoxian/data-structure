#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data-type.h"
#include "sort.h"

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