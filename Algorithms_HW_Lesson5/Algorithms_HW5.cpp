#include <iostream>
#include <math.h>
using namespace std;


//===========================EX.1=========================

void sortArr()
{
	const int SIZE = 3;
	int arr[SIZE][SIZE] = { { 1, 9, 2 }, {5, 7, 6}, {4, 3, 8} };
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	int temp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int a = 0; a < SIZE; a++)
			{
				for (int b = 0; b < SIZE; b++)
				{
					if (arr[a][b] > arr[i][j])
					{
						temp = arr[a][b];
						arr[a][b] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}

//========================================================

//===========================EX.2=========================

void TPK()
{
	int P[11] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		cout << "Enter " << i+1 << " number: ";
		cin >> P[i];
	}

	cout << endl;

	int temp;
	for (int i = 10; i >= 0; i--)
	{
		temp = sqrt(fabs(P[i])) + 5 * pow(P[i], 3);
		if (temp > 400)
			cout << "Element " << i + 1 << " is too large" << endl;
		else
			cout << "Element " << i + 1 << " = " << temp << endl;
	}
}

//========================================================

int main()
{
//EX.1
	sortArr();
	cout << endl;

//EX.2
	TPK();
}