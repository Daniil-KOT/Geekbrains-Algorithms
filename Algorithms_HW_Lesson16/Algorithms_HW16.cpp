#include <iostream>
#include <string>

using namespace std;

const int SZ = 26;
char alphabet[SZ] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

//===================EX.1===================

string caesarCipher(string data, int key)
{
	int idx = 0;
	string cipher = data;
	for (int i = 0; i < data.length(); i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (data[i] == alphabet[j])
			{
				idx = (j + key) % SZ;
				cipher[i] = alphabet[idx];
				break;
			}
		}
	}

	return cipher;
}


string decipher(string cipher, int key)
{
	int idx = 0;
	string message = cipher;
	for (int i = 0; i < cipher.length(); i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (cipher[i] == alphabet[j])
			{
				idx = (j + SZ - key) % SZ;
				message[i] = alphabet[idx];
				break;
			}
		}
	}
	return message;
}

//==========================================

//===================EX.2===================

int* columnsOrder(string key, int columns)
{
	int i, j;
	int *order = new int[columns];
	for (i = 0; i < key.length(); i++)
	{
		for (j = 0; j < SZ; j++)
		{
			if (key[i] == alphabet[j])
			{
				order[i] = j;
				break;
			}
		}
	}

	int* idx = new int [columns];

	for (i = 0; i < columns; i++)
		idx[i] = 0;

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (order[i] > order[j])
				idx[i]++;
		}
	}
	delete[] order;
	return idx;
}

int* sortOrder(int* arr, int columns)
{
	for (int i = 1; i < columns; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
	return arr;
}

void columnsDecipher(char** cipher, int columns, string key)
{
	int i, j;
	int* order = columnsOrder(key, columns);
	order = sortOrder(order, columns);

	char** aux = new char* [columns];
	for (i = 0; i < columns; i++)
	{
		aux[i] = new char[columns];
	}

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			aux[j][order[i]] = cipher[j][i];
		}
	}

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (aux[i][j] == 'X')
				aux[i][j] = ' ';
			cout << aux[i][j];
		}
	}
}

void columnsCipher(string message, int columns, string key)
{
	int i, j, idx = 0;
	char** cipher = new char* [columns];
	char** aux = new char* [columns];

	for (i = 0; i < columns; i++)
	{
		cipher[i] = new char[columns];
		aux[i] = new char[columns];
	}

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (idx < message.length())
			{
				cipher[i][j] = message[idx];
				if (message[idx] == ' ')
					cipher[i][j] = 'X';
				idx++;
			}
			else
			{
				cipher[i][j] = 'X';
			}
		}
	}

	int* order = columnsOrder(key, columns);

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			aux[j][order[i]] = cipher[j][i];
		}
	}

	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < columns; j++)
		{
			cout << aux[i][j] << "  ";
		}
		cout << "\n\n";
	}

	cout << "\n\n";

	columnsDecipher(cipher, columns, key);

	cout << "\n\n";

	delete[] aux;
	delete[] order;
	for (i = 0; i < columns; i++)
		delete[] cipher[i];
}

//==========================================

int main()
{
	cout << "------------------EX.1------------------\n\n";

	string cipher, message, decipherMessage;
	cout << "Enter your message: ";
	getline(cin, message);
	for (int i = 0; i < message.length(); i++)
	{
		message[i] = tolower(message[i]);
	}

	cipher = caesarCipher(message, 3);
	cout << cipher << "\n";

	decipherMessage = decipher(cipher, 3);
	cout << decipherMessage << "\n";

	cout << "\n\n------------------EX.2------------------\n\n";
	
	const int columns = 5; 

	string messageColumns;
	cout << "Enter message: ";
	getline(cin, messageColumns);
	for (int i = 0; i < messageColumns.length(); i++)
	{
		messageColumns[i] = tolower(messageColumns[i]);
	}

	string key;
	cout << "Enter key: "; // for columns = 5, key word was "carts", for columns = 10, key word was random sequence "asdfghjklp"
	cin >> key;
	for (int i = 0; i < key.length(); i++)
	{
		key[i] = tolower(key[i]);
	}

	columnsCipher(messageColumns, columns, key);
}
