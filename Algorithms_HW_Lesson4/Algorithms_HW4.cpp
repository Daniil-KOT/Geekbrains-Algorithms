#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void EX1(int num, string& snum) 
{
    if (num % 2 == 0)
        snum += "0";
    else 
        snum += "1";

    if ((num / 2) != 0)
        EX1(num / 2, snum);
    else 
        return;
}

int EX21(int base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    else
        return(base * EX21(base, exp - 1));
}

int EX22(int base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2 == 0)
    {
        int res = EX22(base, exp / 2);
        return res * res;
    }
    else
        return EX22(base, exp - 1) * base;
}

const int x = 5;
const int y = 5;
int board[x][y];

bool checkBoard(int i, int j)
{
    if (board[i][j] == 1)
        return false;
    else
        return true;
}


int EX3(int x, int y)
{
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else if (checkBoard(x, y) == true)
        return EX3(x, y - 1) + EX3(x - 1, y);
    else
        return 0;
}


int main()
{
//==================EX.1================================

    string binary;
    int decNum;
    cout << "Enter number: ";
    cin >> decNum;
    EX1(decNum, binary);
    reverse(binary.begin(), binary.end());
    cout << "Binary: " << binary << endl << endl; 

//======================================================

//==================EX.2.1==============================

    int base, exp;
    cout << "Enter base number: ";
    cin >> base;
    cout << "Enter exponent number: ";
    cin >> exp;
    cout << "Result is: " << EX21(base, exp) << endl << endl;

//======================================================

//==================EX.2.2==============================

    cout << "Result is: " << EX22(base, exp) << endl << endl;

//======================================================

//==================EX.3================================
    board[0][0] = 0;

    board[1][3] = 1;
    board[2][3] = 1;
    board[4][1] = 1;
    board[2][1] = 1;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    };

    cout << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << EX3(i, j) << " ";
        }
        cout << endl << endl;
    }
//======================================================
}
