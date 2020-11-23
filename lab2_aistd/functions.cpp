#include "functions.h"
#include<iostream>
using namespace std;
void CountingSort(unsigned char* arr, int size)
{

	if (size != 0)
	{
		int max = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		int sizeCount = max + 1;
		int* count = new int[sizeCount];
		for (int i = 0; i < sizeCount; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			count[(int)arr[i]]++;
		}
		int indexArr = 0;
		for (int i = 0; i < sizeCount; i++)
		{
			for (int j = 0; j < count[i]; j++)
			{

				arr[indexArr] = (unsigned char)i;
				indexArr++;
			}
		}
		delete[] count;
	}
}

int Partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int partitionIndex = start;
	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(arr[partitionIndex], arr[end]);
	return partitionIndex;
}

void QuickSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = Partition(arr, start, end);
		QuickSort(arr, start, partitionIndex - 1);
		QuickSort(arr, partitionIndex + 1, end);
	}
}

int BinarySearch(int* arr, int size, int value)
{
	int low = 0, high = size - 1;
	int mid = (low + high) / 2;
	while (low <= high)
	{

		if (value == arr[mid])
		{
			return mid;
		}
		else if (value < arr[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
	}
	return -1;
}

void BubbleSort(int* arr, int size)
{
	bool notSorted = true;
	for (int i = 0; i < size && (notSorted == false || i == 0); i++)
	{
		notSorted = true;
		for (int j = 1; j < size - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr[j - 1], arr[j]);
				notSorted = false;
			}
		}
	}
}

bool isSorted(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}

void BogoSort(int* arr, int size)
{
	while (isSorted(arr, size) == false)
	{
		for (int i = 0; i < size; i++)
		{
			swap(arr[i], arr[rand() % size]);
		}
	}
}