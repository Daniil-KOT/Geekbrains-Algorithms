#include <iostream>
#define SZ 10
#define SIZE 1000
#define TRUE 1 == 1
#define FALSE 1 != 1

typedef int boolean;

using namespace std;

//============================EX.1==================

typedef struct 
{
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int tail;
int items;

void init()
{
	for (int i = 0; i < SZ; ++i)
	{
		arr[i] = NULL;
	}
	tail = 0;
	items = 0;
}

void ins(int pr, int dat)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;

	if (items == SZ)
	{
		cout << "Queue is full";
		return;
	}
	else
	{
		arr[tail] = node;
		items++;
		tail++;
	}
}

Node* rem()
{
	if (items == 0)
	{
		return NULL;
	}
	else
	{
		int i = 0;
		int maxPos = 0;
		Node* max = arr[0];
		for (i = 1; i < tail; i++)
		{
			if (arr[i] == NULL)
				continue;
			if (arr[i]->pr > max->pr)
			{
				max = arr[i];
				maxPos = i;
			}
		}
		arr[maxPos] = NULL;
		items--;
		return max;
	}
}

void printQueue()
{
	cout << "[";
	for (int i = 0; i < SZ; ++i)
	{
		if (arr[i] == NULL)
			cout << "[ *, * ]";
		else
			cout << "[" << arr[i]->pr << ", " << arr[i]->dat << "] ";
	}
	cout << endl;
}

//=========================================================
//========================EX.2=============================

int cursor = -1;
int Stack[SIZE];

boolean push(int data)
{
	if (cursor < SIZE)
	{
		Stack[++cursor] = data;
		return true;
	}
	else
	{
		cout << "Stack overflow." << endl;
		return false;
	}
}

int pop()
{
	if (cursor != -1)
	{
		return Stack[cursor--];
	}
	else
	{
		cout << "Stack is empty." << endl;
		return -1;
	}
}

void decToBin(int num)
{
	if (num % 2 == 0)
		push(0);
	else
		push(1);

	if ((num / 2) != 0)
		decToBin(num / 2);
	else
		return;
}

//=========================================================

int main()
{

//========================EX.1=============================

	init();
	ins(1, 11);
	ins(2, 22);
	ins(5, 33);
	ins(9, 44);
	ins(2, 55);
	ins(4, 66);
	ins(10, 77);
	ins(3, 88);
	ins(1, 99);
	ins(7, 100);
	printQueue();

	for (int i = 0; i < 3; i++)
	{
		Node* n = rem();
		cout << "pr = " << n->pr << ", dat = " << n->dat << endl;
	}
	printQueue();

//=========================================================
//========================EX.2=============================

	int decNum;
	cout << "Enter number: ";
	cin >> decNum;
	decToBin(decNum);
	while (cursor != -1)
	{
		cout << pop();
	}

//=========================================================

}
