#include "functions.h"
#include<iostream>
#include <ctime>
using namespace std;

void Time(int Amount)
{
	cout << endl;
	int* mas1 = new int[Amount];
	int* mas2 = new int[Amount];
	for (int i = 0; i < Amount; i++)
	{
		mas1[i] = rand();
		mas2[i] = rand();
	}
	int start = clock();
	QuickSort(mas1, 0, Amount - 1);
	int stop = clock();
	cout << "Time of QuickSort: " << stop - start << " ms" << endl;
	for (int i = 0; i < Amount; i++)
	{
		cout << mas1[i] << ' ';
	}
	cout << endl;
	delete[] mas1;
	start = clock();
	BubbleSort(mas2, Amount);
	stop = clock();
	cout << "Time of BubleSort: " << stop - start << " ms"<< endl;
	delete[] mas2;
}
int main()
{
	int Amount;
	cout << "Amount of elements for sort: ";
	cin >> Amount;
	Time(Amount);

	return 0;
}