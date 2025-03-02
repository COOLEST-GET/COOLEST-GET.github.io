#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

// 生成随机数数组
int* generateRandomArray(int size);

// 选择排序
// 时间复杂度O(N*N)  空间复杂度O(1)；
// 非稳定排序：存在相同元素时，排序后相同元素的相对位置可能改变。
void selectionSort(int nums[], int size);

// 冒泡排序
// 时间复杂度和平均时间复杂度仍为O(N*N)
// 稳定排序：在遇到相等元素不交换。
void bubbleSort(int nums[], int size);
// 优化版冒泡排序
// 当输入数组完全有序时，可达到最佳时间复杂度O(N)。
void bubbleSortWithFlag(int nums[], int size);

// 插入排序
void insertSort(int nums[], int size);
