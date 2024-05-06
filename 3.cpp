// Write a C++ program to construct a binary search tree with n nodes and implement the following operations
// a.Insert a node   b. all traversals c. Create a clone of a tree and then erase all nodes in the original tree.

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {

        this->left = nullptr;
        this->right = nullptr;
    }

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insert(int key, node *&root)
{
    node *temp = root;
    node *newNode = new node(key);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    else
    {
        while (true)
        {
            if (key < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
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

void rec_InOrder(node *&root)
{
    if (root == nullptr)
        return;

    rec_InOrder(root->left);
    cout << root->data << " ";
    rec_InOrder(root->right);
}

void rec_PreOrder(node *&root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    rec_PreOrder(root->left);
    rec_PreOrder(root->right);
}

void rec_PostOrder(node *&root)
{
    if (root == nullptr)
        return;

    rec_PostOrder(root->left);
    rec_PostOrder(root->right);
    cout << root->data << " ";
}

void itr_Inorder(node *&root)
{
    node *temp = root;
    stack<node *> s;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

void itr_Preorder(node *&root)
{
    node *temp = root;
    stack<node *> s;

    s.push(root);

    while (!s.empty())
    {
        temp = s.top();

        cout << temp->data << " ";
        s.pop();

        if (temp->right != nullptr)
            s.push(temp->right);
        if (temp->left != nullptr)
            s.push(temp->left);
    }
    cout << endl;
}

void itr_PostOrder(node *&root)
{
    node *temp = root;
    stack<node *> s1;
    stack<node *> s2;

    s1.push(root);

    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left != nullptr)
            s1.push(temp->left);
        if (temp->right != nullptr)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

node *cloneTree(node *root)
{
    if (root == nullptr)
        return nullptr;

    node *newNode = new node(root->data);

    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);

    return newNode;
}

void erase(node *root)
{
    if(root==nullptr)
    {
        return;
    }

    erase(root->left);
    erase(root->right);

    cout << root->data << " ";
    delete root;
    root == nullptr;
}

int main()
{
    node *bst = nullptr;

    insert(5, bst);
    insert(3, bst);
    insert(7, bst);
    insert(2, bst);
    insert(4, bst);
    insert(6, bst);
    insert(8, bst);

    cout << "Recursive Inorder: ";
    rec_InOrder(bst);
    cout << endl;
    cout << "Recursive Preorder: ";
    rec_PreOrder(bst);
    cout << endl;
    cout << "Recursive Postorder: ";
    rec_PostOrder(bst);
    cout << endl;
    cout << "Non-recursive Inorder: ";
    itr_Inorder(bst);
    cout << "Non-recursive Preorder: ";
    itr_Preorder(bst);
    cout << "Non-recursive Postorder: ";
    itr_PostOrder(bst);

    node *cloneRoot = cloneTree(bst);

    cout << "Non-recursive Inorder of Clone tree: ";
    itr_Inorder(cloneRoot);

    erase(bst);
}