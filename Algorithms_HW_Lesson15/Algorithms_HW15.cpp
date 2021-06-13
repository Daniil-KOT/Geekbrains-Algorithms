#include <iostream>
#include <string>
using namespace std;

//===================EX.1====================

int hashFunc(string data)
{
	int i, r = 0;
	for (i = 0; i < data.length(); i++)
	{
		r += static_cast <int>(data[i]);
	}
	return r;
}

//===========================================

//===================EX.2====================

void coinsCount(int expectedSum)
{
	int sum = 0;
	int coinsSum = 0;
	int coin50 = 50; 
	int coin10 = 10; 
	int coin5 = 5; 
	int coin2 = 2; 
	int coin1 = 1;

	while (sum != expectedSum)
	{		
		if ((sum + coin50) <= expectedSum)
		{
			sum += coin50;
			coinsSum++;
		}
		else if ((sum + coin10) <= expectedSum)
		{
			sum += coin10;
			coinsSum++;
		}
		else if ((sum + coin5) <= expectedSum)
		{
			sum += coin5;
			coinsSum++;
		}
		else if ((sum + coin2) <= expectedSum)
		{
			sum += coin2;
			coinsSum++;
		}
		else
		{
			sum += coin1;
			coinsSum++;
		}
	}

	cout << "Sum = " << sum << "\n";
	cout << "Number of coins = " << coinsSum << "\n";
}

//===========================================


int main()
{
	cout << "-------------------EX.1-------------------\n\n";
	
	string data;
	cout << "Enter the data to be hashed: ";
	cin >> data;
	int hash = hashFunc(data);
	cout << "Sum of codes: " << hash << "\n";

	cout << "\n\n-------------------EX.2-------------------\n\n";

	coinsCount(98);
}
