// Write a C++ program to construct binary search tree with n nodes and implement the following operations
// a.	Insert a node   b. all traversals (recursive and nonrecursive) c. construct a tree from inorder and preorder traversal

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
    if (root == NULL)
        return;

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
    if (root == NULL)
        return;

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
    if (root == NULL)
        return;

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

int search(int Inorder[], int value, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (Inorder[i] == value)
            return i;
    }
}

node *buildtree(int Inorder[], int PreOrder[], int start, int end)
{
    static int index = 0;

    if (start > end)
        return nullptr;

    node *tNode = new node(PreOrder[index++]);

    if (start == end)
        return tNode;

    int searchIndex = search(Inorder, tNode->data, start, end);

    tNode->left = buildtree(Inorder, PreOrder, start, searchIndex - 1);
    tNode->right = buildtree(Inorder, PreOrder, searchIndex + 1, end);

    return tNode;
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
    // insert(1, bst);
    // insert(0, bst);

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

    // creation of BST from its preorder and Inorder traversal

    int InOrder[] = {2, 3, 4, 5, 6, 7, 8};
    int PreOrder[] = {5, 3, 2, 4, 7, 6, 8};

    int size = sizeof(InOrder) / sizeof(InOrder[0]);

    node *buildRoot = buildtree(InOrder, PreOrder, 0, size - 1);
    cout << "Recursive Postorder of  New build Tree: ";
    rec_PostOrder(buildRoot);
}
