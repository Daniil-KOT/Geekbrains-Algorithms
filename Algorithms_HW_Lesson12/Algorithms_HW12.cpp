#include <iostream>
#include <ctime>

using namespace std;

struct Tree
{
	int key;
	struct Tree* right;
	struct Tree* left;
};

Tree* treeInsert(Tree* t, int data) {
    Tree* newNode;
    newNode = (Tree*)malloc(sizeof(Tree));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    Tree* current = t;
    Tree* parent = t;
    if (t == NULL) {
        t = newNode;
    }
    else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

int countNodes(Tree* root, int & counter)
{
    if (root != NULL)
    {
        counter++;
        countNodes(root->left, counter);
        countNodes(root->right, counter);
    }
    return counter;
}

void printTree(Tree* root)
{
    if (root) 
    {
        cout << root->key;

        if (root->left || root->right) 
        {
            cout << "(";

            if (root->left)
                printTree(root->left);
            else
                cout << "NULL";
            cout << ",";

            if (root->right)
                printTree(root->right);
            else
                cout << "NULL";

            cout << ")";
        }
    }
}

//===============EX.1================

bool checkTreeBalance(Tree* t)
{
    int left = 0;
    int right = 0;

    Tree* current;

    if (t->left == NULL && t->right == NULL)
        return true;
    if (t->left != NULL)
    {
        current = t->left;
        left = countNodes(current, left);
    }
    if (t->right != NULL)
    {
        current = t->right;
        right = countNodes(current, right);
    }
    if (left - 1 == right || left == right)
        return true;
    else
        return false;
}

//===================================

//===============EX.2================

Tree** initTree(Tree** arr, const int trees, int nodes)
{
    int i, j;
    Tree* current = NULL;
    for (i = 0; i < trees; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            current = treeInsert(current, ((rand() % 100) + i));
            arr[i] = current;
        }
        current = NULL;
    }
    return arr;
}

//===================================

//===============EX.3================

double balancedTrees(Tree** arr, const int trees)
{
    double balanced = 0;
   
    for (int i = 0; i < trees; i++)
    {
        if (checkTreeBalance(arr[i]))
            balanced++;
    }
    return balanced;
}

//===================================

//===============EX.4================

bool binRecursiveSearch(Tree* root, int value)
{
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;
    Tree* current = root;
    if (value < current->key)
        return (binRecursiveSearch(current->left, value));
    else
        return (binRecursiveSearch(current->right, value));
}

//===================================

int main()
{
    cout << "____________________EX.1___________________" << endl << endl;

    srand(time(0));
    Tree* t = new Tree;
    t = NULL;
    t = treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);
    treeInsert(t, rand() % 50);

    printTree(t);
    cout << endl;

    if (checkTreeBalance(t))
        cout << "Balanced";
    else
        cout << "Not balanced";

//===============EX.2================

    const int trees = 50;
    int nodes = 10000;
    Tree* arr[trees];
    initTree(arr, trees, nodes);

//===================================

    cout << endl << endl << "____________________EX.3___________________" << endl << endl;
    
    cout << "Trees balanced: " << balancedTrees(arr, trees) << endl;
    cout << "Percent of balanced trees: " << ((balancedTrees(arr, trees)/trees) * 100) << "%";

//===================================

    cout << endl << endl << "____________________EX.4___________________" << endl << endl;

    int value;

    cout << "Please, enter the value to be found in tree: ";
    cin >> value;

    if (binRecursiveSearch(t, value))
        cout << "There is " << value << " in the tree." << endl;
    else
        cout << "There is no " << value << " in the tree." << endl;
}
