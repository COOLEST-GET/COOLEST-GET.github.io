#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

// �������������
int* generateRandomArray(int size);

// ѡ������
// ʱ�临�Ӷ�O(N*N)  �ռ临�Ӷ�O(1)��
// ���ȶ����򣺴�����ͬԪ��ʱ���������ͬԪ�ص����λ�ÿ��ܸı䡣
void selectionSort(int nums[], int size);

// ð������
// ʱ�临�ӶȺ�ƽ��ʱ�临�Ӷ���ΪO(N*N)
// �ȶ��������������Ԫ�ز�������
void bubbleSort(int nums[], int size);
// �Ż���ð������
// ������������ȫ����ʱ���ɴﵽ���ʱ�临�Ӷ�O(N)��
void bubbleSortWithFlag(int nums[], int size);

// ��������
void insertSort(int nums[], int size);
