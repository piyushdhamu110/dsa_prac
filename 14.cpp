// Write a C++ program to construct AVL Tree. Implement following operations.
// a.Insert b. level order traversal c. Print height of tree

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
    int height;

    node(int key)
    {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

int height(node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}


node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

node *insert(node *root, int key)
{
    node *newNode = new node(key);

    if (root == nullptr)
        return newNode;

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void levelOrder(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        cout << current->key << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int getHeight(node *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

int main()
{
    node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Level traversal of the AVL tree is:\n";
   
    levelOrder(root);

    cout << "height: " << getHeight(root) << endl;
    return 0;
}
