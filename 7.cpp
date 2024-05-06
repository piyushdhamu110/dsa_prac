// Write a C++ program to inorder threaded binary search tree with n nodes and implement following operations 1.Insert a new node 2. Inorder traversal
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    bool lThread, rThread;

    node()
    {
        this->left = nullptr;
        this->right = nullptr;
        lThread = rThread = true;
    }
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        lThread = rThread = true;
    }
};

void insert(node *&root, int data)
{
    node *temp = root->left;
    node *newNode = new node(data);

    if (temp == nullptr)
    {
        root->left = newNode;
        newNode->left = root;
        newNode->right = root;
        root->lThread = false;
        return;
    }
    else
    {
        while (true)
        {
            if (data < temp->data)
            {
                if (temp->lThread == true)
                {
                    newNode->left = temp->left;
                    temp->left = newNode;
                    temp->lThread = false;
                    newNode->right = temp;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->rThread == true)
                {
                    newNode->right = temp->right;
                    temp->right = newNode;
                    temp->rThread = false;
                    newNode->left = temp;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void inOrder(node *&root)
{
    node *temp = root->left;

    if (root == nullptr)
        return;

    while (temp != root)
    {
        while (temp->lThread == false)
        {
            temp = temp->left;
        }

        cout << temp->data << " ";

        if (temp->rThread == false)
        {
            temp = temp->right;
        }

        else
        {
            while (temp->rThread == true && temp->right != root)
            {
                temp = temp->right;
                cout << temp->data << " ";
            }
            temp = temp->right;
        }
    }
    cout << endl;
}

int main()
{
    node *dummy = new node(999);

    insert(dummy, 6);
    insert(dummy, 3);
    insert(dummy, 8);
    insert(dummy, 1);
    insert(dummy, 5);
    insert(dummy, 7);
    insert(dummy, 11);
    insert(dummy, 9);
    insert(dummy, 13);

    cout << "Inorder: ";
    inOrder(dummy);
}