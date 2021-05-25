#include <iostream>
#include <ctime>
using namespace std;


void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void initArr(int* arr, int size, int range)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % range;
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}


//=============================EX.1===================================

void qs(int* arr, int first, int last)
{
	int i, j, x;
	i = first;
	j = last;
	x = arr[(first + last) / 2];

	do 
	{
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j)
		{
			swapInt(arr[i], arr[j]); 
			i++;
			j--;
		}
	} while (i <= j);

	if (first < j)
		qs(arr, first, j);
	if (i < last)
		qs(arr, i, last);
}

void qsU(int* arr, int first, int last)
{
	if (last + 1 <= 11)
	{
		for (int i = 0; i <= last; i++)
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
				swapInt(arr[j - 1], arr[j]);
	}
	else
	{
		if (arr[first] > arr[(first + last) / 2])
			swapInt(arr[first], arr[(first + last) / 2]);
		if (arr[(first + last) / 2] > arr[last])
			swapInt(arr[(first + last) / 2], arr[last]);
		if (arr[first] > arr[(first + last) / 2])
			swapInt(arr[first], arr[(first + last) / 2]);
		qs(arr, first, last);
	}
}

//====================================================================

//=============================EX.2===================================

void bucket(int* arr, int size)
{
	const int max = size;
	const int b = 10;

	int buckets[b][26];

	for (int i = 0; i < b; i++)
	{
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 1000000000; digit *= 10)
	{
		for (int i = 0; i < max; i++)
		{
				int d = (arr[i] / digit) % b;
				int counter = buckets[d][max];
				buckets[d][counter] = arr[i];
				counter++;
				buckets[d][max] = counter;
		}

		int idx = 0;

		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < buckets[i][max]; j++)
			{
					arr[idx++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
	}
}

//====================================================================


int main()
{
	const int SIZE = 25;
	int arr[SIZE];

	initArr(arr, SIZE, 100);

	printArr(arr, SIZE);

	bucket(arr, SIZE);

	printArr(arr, SIZE);

	//	qsU(arr, 0, SIZE - 1);

/*	int arr1[12] = { 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };

	printArr(arr1, 12);
	
	bucket(arr1, 12);

	printArr(arr1, 12); */

}

