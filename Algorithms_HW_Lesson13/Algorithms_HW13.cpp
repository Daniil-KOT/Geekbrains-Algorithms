#include <iostream>

using namespace std;

const int SZ = 6;
int matrix[SZ][SZ] =
{
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
};

int visited[SZ] = { 0 };

struct Node 
{
    int dat;
    struct Node* next;
    struct Node* prev;
};

struct List 
{
    struct Node* head;
    struct Node* tail;
    int size;
};

struct Prior
{
    int idx;
    int links;
};

Prior* arr[SZ];
int items;
int tail;

void initPrior()
{
    for (int i = 0; i < SZ; ++i)
    {
        arr[i] = NULL;
    }
    tail = 0;
    items = 0;
}

void insPrior(int links, int idx)
{
    Prior* node = new Prior;
    node->idx = idx;
    node->links = links;

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

Prior* remPrior()
{
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int i;
        int maxPos = 0;
        Prior* max = arr[0];
        for (i = 1; i < tail; i++)
        {
            if (arr[i]->links > max->links)
            {
                max = arr[i];
                maxPos = i;
            }
        }
        for (int j = maxPos; j < tail; j++)
        {
            arr[j] = arr[j + 1];
        }
        items--;
        tail--;
        return max;
    }
}

void initArr(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

void initList(List* lst)
{
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
};

bool listEnqueue(List* queue, int val)
{
    Node* tmp = new Node;
    if (tmp == NULL)
    {
        cout << "Out of memory" << endl;
        return false;
    }

    tmp->dat = val;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL)
    {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL)
    {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
};

bool listPush(List* stack, int value) {
    Node* tmp = new Node;
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

int popList(List* stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    Node* tmp = stack->head;
    int data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

int listDequeue(List* queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    Node* tmp = queue->head;
    int data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    delete tmp;
    queue->size--;
    return data;
};

void printNode(Node* n)
{
    if (n == NULL)
    {
        cout << "[]";
        return;
    }
    cout << "[" << n->dat << "]";
};

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
    cout << endl;
}

void resetArr(int* arr, const int sz)
{
    for (int i = 0; i < sz; i++)
        arr[i] = 0;
}

//===================EX.1=====================

int depthTraverse(int st, const int sz)
{
    List* lst = new List;
    initList(lst);
    int r;
    int vertices = 0;
    
    int visited[SZ];

    for (int i = 0; i < sz; i++)
        visited[i] = 0;

    listPush(lst, st);
    while (lst->size > 0)
    {
        int idx = popList(lst);
        if (visited[idx] == 1)
            continue;
        visited[idx] = 1;
        for (r = 0; r < sz; r++)
        {
            if (matrix[idx][r] == 1 && visited[r] != 1)
            {
                listPush(lst, r);
            }
        }
        cout << idx << " ";
        vertices++;
    }
    cout << endl;
    delete lst;
    return vertices;
}

//============================================

//===================EX.2=====================

int linkCounter[SZ] = { 0 };

void vertexLinkCounterDFS(int st, const int sz)
{
    int r;
    visited[st] = 1;
    for (r = 0; r < sz; r++)
    {
        if (matrix[st][r] == 1 && st != r)
            linkCounter[r]++;

        if (matrix[st][r] == 1 && visited[r] != 1)
        {
            vertexLinkCounterDFS(r, sz);
        }
    }
}

//============================================

//===================EX.3=====================

void startVertexLinkCounter(List* lst, int st, int& counter, const int sz)
{
    if (lst->size < 1)
    {
        listPush(lst, st);
    }

    int r;
    visited[st] = 1;
    for (r = 0; r < sz; r++)
    {
        if (matrix[st][r] == 1 && visited[r] != 1)
        {
            if (matrix[lst->head->dat][r] == 1)
                counter++;
            startVertexLinkCounter(lst, r, counter, sz);
        }
    }
}

//============================================

//===================EX.4=====================

void matrixOrdinalScale(Prior* list, int st, const int size)
{
    int i;

    int vertices = depthTraverse(st, size);
    cout << endl;

    cout << "Number of vertices: " << vertices << endl << endl;

    vertexLinkCounterDFS(st, size);

    for (i = 0; i < size; i++)
        insPrior(linkCounter[i], i);

    for (i = 0; i < size; i++)
    {
        list = remPrior();
        cout << "Links to vertex " << list->idx + 1 << ": " << list->links << endl;
    }
}

//============================================

int main()
{
    cout << "=================EX.1===================" << endl << endl;

    depthTraverse(0, SZ);
    depthTraverse(2, SZ);
    depthTraverse(1, SZ);

    cout << endl << endl << "=================EX.2===================" << endl << endl;

    vertexLinkCounterDFS(0, SZ);
    for (int i = 0; i < SZ; i++)
        cout << "Links to vertex " << i + 1 << ": " << linkCounter[i] << endl;
    initArr(linkCounter, SZ);

    cout << endl << endl << "=================EX.3===================" << endl << endl;

    List* lst = new List;
    initList(lst);
    int counter = 0;
    resetArr(visited, SZ);
    
    startVertexLinkCounter(lst, 0, counter, SZ);
    resetArr(visited, SZ);
    cout << endl << endl;
    cout << counter << endl;

    cout << endl << endl << "=================EX.3===================" << endl << endl;

    Prior* list = new Prior;
    matrixOrdinalScale(list, 0, SZ);

    delete lst;
    delete list;
}
