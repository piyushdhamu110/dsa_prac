// Department maintains student information.the file contains rollno, name, division, and address.Allow user to add, edit, delete, insert and search information of student.use sequential file to maintain the data

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    string division;
    string address;

    Student(int rollNo, const string &name, const string &division, const string &address)
    {
        this->name = name;
        this->rollNo = rollNo;
        this->division = division;
        this->address = address;
    }
};

const string FILE_PATH = "student_data.txt";

void addStudent(const Student &student)
{
    ofstream outFile(FILE_PATH, ios::app);

    if (outFile.is_open())
    {
        outFile << student.rollNo << "," << student.name << "," << student.division << "," << student.address << endl;
        cout << "Student added successfully!" << endl;
        outFile.close();
    }
    else
    {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

vector<Student> readStudentsFromFile()
{
    vector<Student> students;

    ifstream inFile(FILE_PATH);

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);

            string token;
            vector<string> tokens;

            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() == 4)
            {
                int rollNo = stoi(tokens[0]);
                students.emplace_back(rollNo, tokens[1], tokens[2], tokens[3]);
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open file for reading." << endl;
    }
    return students;
}

void displayStudent(const Student &student)
{
    cout << "Roll No: " << student.rollNo << ", Name: " << student.name
         << ", Division: " << student.division << ", Address: " << student.address << endl;
}

void displayAllStudents()
{
    vector<Student> students = readStudentsFromFile();

    cout << "List of students:" << endl;

    for (size_t i = 0; i < students.size(); ++i)
    {
        displayStudent(students[i]);
    }
}

void deleteStudent(int rollNoToDelete)
{
    vector<Student> students = readStudentsFromFile();

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->rollNo == rollNoToDelete)
        {
            students.erase(it);
            found = true;
            break;
        }
    }

    if (found)
    {
        ofstream outFile(FILE_PATH);
        if (outFile.is_open())
        {
            for (const auto &student : students)
            {
                outFile << student.rollNo << "," << student.name << "," << student.division << "," << student.address << endl;
            }
            cout << "Student with Roll No " << rollNoToDelete << " deleted successfully!" << endl;
            outFile.close();
        }
        else
        {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    else
    {
        cout << "Student with Roll No " << rollNoToDelete << " not found!" << endl;
    }
}

void insertStudent(const Student &newStudent, size_t position)
{
    vector<Student> students = readStudentsFromFile();

    if (position >= 0 && position <= students.size())
    {
        students.insert(students.begin() + position, newStudent);

        ofstream outFile(FILE_PATH);
        if (outFile.is_open())
        {
            for (const auto &student : students)
            {
                outFile << student.rollNo << "," << student.name << "," << student.division << "," << student.address << endl;
            }
            cout << "Student inserted successfully!" << endl;
            outFile.close();
        }
        else
        {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    else
    {
        cout << "Invalid position! Please provide a position between 0 and " << students.size() << "." << endl;
    }
}

void searchStudent(int rollNoToSearch)
{
    vector<Student> students = readStudentsFromFile();

    bool found = false;
    for (const auto &student : students)
    {
        if (student.rollNo == rollNoToSearch)
        {
            displayStudent(student);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with Roll No " << rollNoToSearch << " not found!" << endl;
    }
}

int main()
{
    while (true)
    {
        cout << "\n1. Add Student\n2. Display All Students\n3. Delete Student\n4. Insert Student\n5. Search Student\n6. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int rollNo;
            string name, division, address;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Division: ";
            cin >> division;
            cout << "Enter Address: ";
            cin >> address;
            addStudent(Student(rollNo, name, division, address));
            break;
        }
        case 2:
            displayAllStudents();
            break;
        case 3:
        {
            int rollNoToDelete;
            cout << "Enter Roll No of the student to delete: ";
            cin >> rollNoToDelete;
            deleteStudent(rollNoToDelete);
            break;
        }
        case 4:
        {
            int rollNo;
            string name, division, address;
            size_t position;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Division: ";
            cin >> division;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter position to insert (0 - end of the list): ";
            cin >> position;
            insertStudent(Student(rollNo, name, division, address), position);
            break;
        }
        case 5:
        {
            int rollNoToSearch;
            cout << "Enter Roll No of the student to search: ";
            cin >> rollNoToSearch;
            searchStudent(rollNoToSearch);
            break;
        }
        case 6:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
