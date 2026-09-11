#include <iostream>
#include <string>
using namespace std;


struct Student
{
    int rollNo;
    string name;
    float marks;
};


void addStudent(Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Enter Roll Number: ";
        cin >> (s + i)->rollNo;

        cout << "Enter Name: ";
        cin >> (s + i)->name;

        cout << "Enter Marks: ";
        cin >> (s + i)->marks;
    }
}


void displayStudents(Student *s, int n)
{
    cout << "\n===== STUDENT RECORDS =====" << endl;

    cout << "\nRoll No\tName\tMarks" << endl;
    cout << "--------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << (s + i)->rollNo << "\t"
             << (s + i)->name << "\t"
             << (s + i)->marks << endl;
    }
}


void searchStudent(Student *s, int n)
{
    int roll, found = 0;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if ((s + i)->rollNo == roll)
        {
            cout << "\nStudent Found!" << endl;
            cout << "Roll Number: " << (s + i)->rollNo << endl;
            cout << "Name: " << (s + i)->name << endl;
            cout << "Marks: " << (s + i)->marks << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\nStudent not found!" << endl;
    }
}


void updateStudent(Student *s, int n)
{
    int roll, found = 0;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if ((s + i)->rollNo == roll)
        {
            cout << "\nEnter New Name: ";
            cin >> (s + i)->name;

            cout << "Enter New Marks: ";
            cin >> (s + i)->marks;

            cout << "\nStudent record updated successfully!" << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\nStudent not found!" << endl;
    }
}


int main()
{
    Student students[100];
    int n, choice;

    cout << "===== STUDENT MANAGEMENT SYSTEM =====" << endl;

    cout << "\nEnter number of students: ";
    cin >> n;

 
    addStudent(students, n);

    do
    {
        cout << "\n\n===== MENU =====" << endl;
        cout << "1. Display Students" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayStudents(students, n);
                break;

            case 2:
                searchStudent(students, n);
                break;

            case 3:
                updateStudent(students, n);
                break;

            case 4:
                cout << "\nProgram terminated." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
