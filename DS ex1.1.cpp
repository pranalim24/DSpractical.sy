#include <iostream>
#include <string>
using namespace std;


struct Student
{
    int rollNo;
    string name;
    float marks;
};

int main()
{
    Student students[100];
    int n, i;

    cout << "===== STUDENT MANAGEMENT SYSTEM =====" << endl;

   
    cout << "\nEnter number of students: ";
    cin >> n;

   
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << ":" << endl;

        cout << "Roll Number: ";
        cin >> students[i].rollNo;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Marks: ";
        cin >> students[i].marks;
    }
    cout << "\n\n===== STUDENT DETAILS =====" << endl;

    cout << "\nRoll No\tName\tMarks" << endl;
    cout << "--------------------------" << endl;

    for (i = 0; i < n; i++)
    {
        cout << students[i].rollNo << "\t"
             << students[i].name << "\t"
             << students[i].marks << endl;
    }

    return 0;
}
