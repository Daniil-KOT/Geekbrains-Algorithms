#include <iostream>
#define TRUE 1 == 1
#define FALSE 1 != 1
using namespace std;

typedef struct Node
{
	int dat;
	struct Node *next;
} Node;

typedef struct
{
	Node* head;
	int size;
} List;

void init(List* lst)
{
	lst->head = NULL;
	lst->size = 0;
}

void ins(List* lst, int data)
{
	Node* New = (Node*)malloc(sizeof(Node));
	New->dat = data;
	New->next = NULL;

	Node* current = lst->head;
	if (current == NULL)
	{
		lst->head = New;
		lst->size++;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = New;
		lst->size++;
	}
}

Node* rmList(List* lst, int data)
{
	Node* current = lst->head;
	Node* parent = NULL;
	if (current == NULL)
		return NULL;

	while (current != NULL && current->dat != data)
	{
		parent = current;
		current = current->next;
	}
	if (current->dat != data)
	{
		return NULL;
	}
	if (current == lst->head)
	{
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

void printNode(Node* n)
{
	if (n == NULL)
	{
		cout << "[]";
		return;
	}
	cout << "[" << n->dat << "] ";
}

void printList(List* lst)
{
	Node* current = lst->head;
	if (current == NULL)
	{
		printNode(current);
	}
	else
	{
		do {
			printNode(current);
			current = current->next;
		} while (current != NULL);
	}
	cout << " Size: " << lst->size << endl;
}

//=======================EX.1=======================

typedef struct Node1
{
	char dat;
	struct Node1* next;
	struct Node1* previous;
} Node1;

typedef struct
{
	Node1* head;
	Node1* tail;
	int size;
} List1;

void init1(List1* lst)
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void pushFront(List1* lst, char data)
{
	Node1* New = (Node1*)malloc(sizeof(Node1));
	New->dat = data;
	New->previous = NULL;
	New->next = lst->head;

	if (lst->head != NULL)
	{
		lst->head->previous = New;
	}

	if (lst->tail == NULL)
	{
		lst->tail = New;
	}
	lst->head = New;
	lst->size++;
}

typedef int boolean;

boolean checkLeftBracket(char bracket)
{
	if (bracket == '(' || bracket == '[' || bracket == '{')
		return TRUE;
	else
		return FALSE;
}

boolean checkRightBracket(char bracket)
{
	if (bracket == ')' || bracket == ']' || bracket == '}')
		return TRUE;
	else
		return FALSE;
}

char pairBracket(char bracket)
{
	if (bracket == ')')
		return '(';
	else if (bracket == ']')
		return '[';
	else if (bracket == '}')
		return '{';
	else
		return bracket;
}

void checkBracketSequence(char* bracket)
{
	List1* list = (List1*)malloc(sizeof(List1));
	init1(list);
	Node1* current = NULL;
	boolean sequence = TRUE;
	int i = 0;
	while (i < strlen(bracket))
	{
		if (checkLeftBracket(bracket[i]) == TRUE)
		{
			pushFront(list, bracket[i]);
		}
		else if (checkRightBracket(bracket[i]) == TRUE)
		{
			if (list->size == 0)
			{
				sequence = FALSE;
				break;
			}
			if (current == NULL)
			{
				current = list->head;
			}
			char pair = current->dat;
			current = current->next;
			if (pairBracket(bracket[i]) != pair)
			{
				sequence = FALSE;
				break;
			}
		}
		i++;
	}
	if (sequence == TRUE)
	{
		cout << "Right sequence!" << endl;
	}
	else
		cout << "Wrong sequence!" << endl;
}

//==================================================

//=======================EX.2=======================

Node* copyList(List* lst)
{
	int i = 1;
	Node* current = lst->head;
	Node* copy = (Node*)malloc(sizeof(Node));
	copy = current;
	if (current == NULL)
		return NULL;
	Node* copyFirst = copy;

	while (i < lst->size)
	{
		copy = current;
		current = current->next;
		i++;
	}
	return copyFirst;
}

//==================================================

//=======================EX.3=======================

void checkSortList(List* lst)
{
	int i = 1;
	int tmp = 0;

	if (lst->size == 0)
	{
		cout << "List is empty." << endl;
		return;
	}
	else if (lst->size == 1)
	{
		cout << "There is only one value in the list." << endl;
		return;
	}

	tmp = lst->head->dat;
	Node* ptr = lst->head;

	while (i < lst->size)
	{
		if (tmp <= ptr->dat)
		{
			tmp = ptr->dat;
			ptr = ptr->next;
			i++;
		}
		else
		{
			cout << "List is not sorted." << endl;
			return;
		}
	}
	cout << "List is sorted" << endl;
	return;
}

//==================================================

int main()
{
//=======================EX.1=======================

	char bracket[] = { '[', '2', '/', '{', '5', '*', '(', '4', '+', '7', ')', '}', ']' };
	checkBracketSequence(bracket);

//==================================================

//=======================EX.2=======================

	List* lst1 = (List*)malloc(sizeof(List));
	List* lstCP = (List*)malloc(sizeof(List));
	Node* copy = (Node*)malloc(sizeof(Node));
	init(lst1);
	init(lstCP);

	ins(lst1, 10);
	ins(lst1, 12);
	ins(lst1, 47);
	ins(lst1, 33);
	ins(lst1, 2);
	ins(lst1, 6);

	printList(lst1);
	cout << endl;

	copy = copyList(lst1);
	lstCP->head = copy;

	printList(lstCP);

//==================================================

//=======================EX.3=======================

	List* lst = (List*)malloc(sizeof(List));
	init(lst);

	ins(lst, 1);
	ins(lst, 3);
	ins(lst, 2);
	ins(lst, 11);
	ins(lst, 4);
	ins(lst, 5);

	checkSortList(lst);

//==================================================
}