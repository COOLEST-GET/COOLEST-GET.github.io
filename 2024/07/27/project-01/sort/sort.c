#include "sort.h"

int* generateRandomArray(int size)
{
	int* nums = (int*)malloc(sizeof(int) * size);
	if (nums == NULL)
	{
		printf("申请内存失败\n");
		return 0;
	}

	//生成随机数种子
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
	{
		nums[i] = rand() % 90;
	}

	printf("初始数组: ");
	for (int j = 0; j < size; j++)
	{
		printf("%d ", nums[j]);
	}
	printf("\n");

	return nums;
}

void selectionSort(int nums[], int size)
{
	int n = size;
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;

		for (int j = i+1; j < n; j++)
		{
			if (nums[j] < nums[k])
				k = j;
		}

		int tmp = nums[i];
		nums[i] = nums[k];
		nums[k] = tmp;
	}

	printf("选择排序后的数组: ");
	for (int u = 0; u < n; u++)
	{
		printf("%d ", nums[u]);
	}
	printf("\n");
}

void bubbleSort(int nums[], int size)
{
	int tmp = 0;
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}

	printf("冒泡排序后的数组: ");
	for (int u = 0; u < size; u++)
	{
		printf("%d ", nums[u]);
	}
	printf("\n");
}
void bubbleSortWithFlag(int nums[], int size) {
	// 外循环：未排序区间为 [0, i]
	for (int i = size - 1; i > 0; i--) {
		bool flag = false;
		// 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

void insertSort(int nums[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int base = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] > base)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		base = nums[j + 1];
	}
	printf("插入排序后的数组: ");
	for (int u = 0; u < size; u++)
	{
		printf("%d ", nums[u]);
	}
	printf("\n");
}