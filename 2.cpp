// Input a list of more than 20 correctly spelled lowercase words. The words are inserted into the hash table. Handle collision using separate chaining. After the reading of the dictionary file is complete, the program prompts the user for input. After input is obtained, each word that the user enters into the program is looked up within the hash table to see if it exists. If the user entered word exists within the hash table, then that word is spelled correctly.

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string word;
    node *next;

    node()
    {
        this->word = "";
        this->next = nullptr;
    }

    node(string word)
    {
        this->word = word;
        this->next = nullptr;
    }
};

class hashing
{
public:
    node *hashtable[20];

    hashing()
    {
        for (int i = 0; i < 20; i++)
        {
            hashtable[i] = nullptr;
        }
    }

    int Index(string word);
    void insert(string word);
    void search(string word);
    void display();
};

int hashing::Index(string word)
{
    int index = 0;

    for (int i = 0; i < word.size(); i++)
    {
        index += (word[i] - 'a' + 1);
    }
    index = index % 20;

    return index;
}

void hashing::insert(string word)
{
    int index = Index(word);

    node *newNode = new node(word);

    newNode->next = hashtable[index];
    hashtable[index] = newNode;

    cout << word << " Inserted successfully\n";
}

void hashing::search(string word)
{
    int index = Index(word);

    node *temp = hashtable[index];

    while (true)
    {

        if (temp == nullptr)
        {
            cout << "Not found\n";
            return;
        }

        if (temp->word == word)
        {
            cout << "Spelled correctly: " << word << endl;
            return;
        }

        temp = temp->next;
    }
}

void hashing::display()
{
    for (int i = 0; i < 20; i++)
    {
        node *temp = hashtable[i];

        if (temp == nullptr)
        {
            cout << "Empty\n";
        }
        else
        {
            cout << "Word: ";
            while (temp != nullptr)
            {
                cout << temp->word << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    hashing h;

    ifstream Input("2Data.txt");

    string word;

    cout << "-----------------Inserting-----------------\n";

    while (Input >> word)
    {
        h.insert(word);
    }

    cout << "-----------------Display-----------------\n";

    h.display();

    cout << "-----------------Searching-----------------\n";

    h.search("six");
}