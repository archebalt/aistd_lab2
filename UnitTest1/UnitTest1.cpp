#include "pch.h"
#include<iostream>
using namespace std;
#include "CppUnitTest.h"
#include "../lab2_aistd/functions.h"
#include "../lab2_aistd/functions.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		int amount = 1000;
		int* arr = new int[amount];
		TEST_METHOD(quicksort)
		{
			for (int i = 0; i < amount; i++)
			{
				arr[i] = rand();
			}
			QuickSort(arr, 0, amount-1);
			for (int i = 1; i < 20; i++)
			{
				Assert::IsTrue(arr[i] >= arr[i - 1]);
			}

		}
		TEST_METHOD(bubblesort)
		{
			for (int i = 0; i < amount; i++)
			{
				arr[i] = rand();
			}
			BubbleSort(arr, amount);
			for (int i = 1; i < 20; i++)
			{
				Assert::IsTrue(arr[i] >= arr[i - 1]);
			}
			delete[] arr;
		}
		TEST_METHOD(binarysearch)
		{
			int arr2[6];
			arr2[0] = 2;
			arr2[1] = 10;
			arr2[2] = 89;
			arr2[3] = 101;
			arr2[4] = 102;
			arr2[5] = 456;
			Assert::AreEqual(BinarySearch(arr2, 6, 2), 0);
			Assert::AreEqual(BinarySearch(arr2, 6, 10), 1);
			Assert::AreEqual(BinarySearch(arr2, 6, 89), 2);
			Assert::AreEqual(BinarySearch(arr2, 6, 101), 3);
			Assert::AreEqual(BinarySearch(arr2, 6, 456), 5);
			Assert::AreEqual(BinarySearch(arr2, 6, 10000), -1);
		}
		TEST_METHOD(countingsort)
		{
			int N = 30;
			unsigned char* ch = new unsigned char[N];
			for (int i = 0; i < N; i++)
			{
				ch[i] = (char) +rand() % 256;
			}
			CountingSort(ch, N);
			for (int i = 1; i < N; i++)
			{
				Assert::IsTrue(ch[i] >= ch[i - 1]);
			}
			delete[]ch;
		}
		TEST_METHOD(bogosort)
		{
			int mas[4];
			mas[0] = 20;
			mas[1] = 5;
			mas[2] = 7;
			mas[3] = 1;
			BogoSort(mas, 4);
			for (int i = 1; i < 4; i++)
			{
				Assert::IsTrue(mas[i] >= mas[i - 1]);
			}
		}
	};
}
