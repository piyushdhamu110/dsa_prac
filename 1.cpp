// Consider the student database of N students and their marks. Make use of a hash table implementation to quickly insert and lookup students' Rollno and marks. Implement collision handling techniques-  linear probing with chaining without replacement.

#include <iostream>
#include <vector>
using namespace std;


struct chain
{
    int rollNo, marks, chain;
};

class hashing
{
public:
    vector<chain> hashtable;
    int size;

    hashing(int tableSize)
    {
        this->size = tableSize;
        
        hashtable.resize(size);
        for (int i = 0; i < size; i++)
        {
            hashtable[i].rollNo = -1;
            hashtable[i].marks = 0;
            hashtable[i].chain = -1;
        }
    }

    void insert(int rollNo, int marks);
    void search(int rollNo);
    void display();
};

void hashing::insert(int rollNo, int marks)
{
    int index = rollNo % size;
    int startingIndex = index;

    while (hashtable[index].chain != -1)
    {
        index = (hashtable[index].chain) % size;
    }

    int store = index;

    while (hashtable[index].rollNo != -1)
    {
        index = (index + 1) % size;
        if (index == startingIndex)
        {
            cout << "Hashtable is full. No more entries can be inserted.\n";
            return;
        }
    }

    if (store != index)
    {
        hashtable[store].chain = index;
    }
    hashtable[index].rollNo = rollNo;
    hashtable[index].marks = marks;
}

void hashing::search(int rollNo)
{
    int index = rollNo % size;
    int startingIndex = index;

    while (hashtable[index].chain != -1)
    {
        if (rollNo == hashtable[index].rollNo)
        {
            cout << "RollNo: " << hashtable[index].rollNo << " Marks: " << hashtable[index].marks;
            return;
        }
        index = (hashtable[index].chain) % size;
    }

    while (hashtable[index].rollNo != -1)
    {
        if (rollNo == hashtable[index].rollNo)
        {
            cout << "RollNo: " << hashtable[index].rollNo << " Marks: " << hashtable[index].marks;
            return;
        }
        index = (index + 1) % size;
        if (index == startingIndex)
        {
            cout << "Not found\n";
            return;
        }
    }
}

void hashing::display()
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Index " << i << ": ";
        if (hashtable[i].rollNo != -1)
        {
            cout << "Key: " << hashtable[i].rollNo << " Marks: " << hashtable[i].marks << ", Chain: " << hashtable[i].chain;
        }
        else
        {
            cout << "Empty";
        }
        cout << endl;
    }
}

int main()
{
    int tableSize;
    cout << "Enter the size of the hashtable: ";
    cin >> tableSize;

    hashing h(tableSize);

    cout << "-----------------Inserting-----------------\n";

    h.insert(32, 98);
    h.insert(25, 84);
    h.insert(21, 65);
    h.insert(29, 75);
    h.insert(31, 55);
    h.insert(10, 14);
    h.insert(2, 61);
    h.insert(5, 32);
    h.insert(75, 15);
    h.insert(61, 95);

    h.display();

    cout << "-----------------Searching-----------------\n";

    h.search(75);
}
