#include "sort.h"

int main()
{
	int size = 10;
	int* nums = generateRandomArray(size);

	if (nums != NULL)
	{
		selectionSort(nums, size);
		bubbleSort(nums, size);
		insertSort(nums, size);
		free(nums);
	}



	return 0;
}