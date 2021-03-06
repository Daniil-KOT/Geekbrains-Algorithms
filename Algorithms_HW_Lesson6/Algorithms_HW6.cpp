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

	int sArr[max] = { 0 };
	int iArr[max] = { 0 };


	int sind = 0;
	int iind = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			sArr[sind++] = arr[i];
			iArr[iind++] = i;
		}
	}

	int buckets[b][max + 1];

	for (int i = 0; i < b; i++)
	{
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 1000000000; digit *= 10)
	{
		for (int i = 0; i < max; i++)
		{
				int d = (sArr[i] / digit) % b;
				int counter = buckets[d][max];
				buckets[d][counter] = sArr[i];
				counter++;
				buckets[d][max] = counter;
		}

		int idx = 0;

		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < buckets[i][max]; j++)
			{
					sArr[idx++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
	}
	
	int idx = 0;

	for (int i = 0; i < size; i++)
	{
		if (sArr[i] != 0)
		{
			arr[iArr[idx++]] = sArr[i];
		}
	}
}

//====================================================================


int main()
{
//=============================EX.1===================================

	const int SIZE = 25;

	int arr[SIZE];

	initArr(arr, SIZE, 100);

	printArr(arr, SIZE);

	qsU(arr, 0, SIZE - 1);

	printArr(arr, SIZE);

//====================================================================

//=============================EX.2===================================

	int arr1[SIZE];

	initArr(arr1, SIZE, 100);

	printArr(arr1, SIZE);

	bucket(arr1, SIZE);

	printArr(arr1, SIZE);

//====================================================================
}

