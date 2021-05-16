#include <iostream>
using namespace std;

int main()
{
    int x;
    bool prime = true;
    cout << "Enter the number: ";
    cin >> x;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime == true)
        cout << "The number is prime." << endl;
    else
        cout << "The number is not prime." << endl;
}

