#include <iostream>
#include <string>
using namespace std;


struct Employee
{
    int id;
    string name;
    float salary;
    Employee *next;
};


void insertEmployee(Employee *&head)
{
    Employee *newNode = new Employee;

    cout << "\nEnter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    cout << "Enter Salary: ";
    cin >> newNode->salary;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Employee *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nEmployee inserted successfully!" << endl;
}

void displayEmployees(Employee *head)
{
    if (head == NULL)
    {
        cout << "\nList is empty!" << endl;
        return;
    }

    Employee *temp = head;

    cout << "\n===== EMPLOYEE RECORDS =====" << endl;
    cout << "\nID\tName\tSalary" << endl;
    cout << "---------------------------" << endl;

    while (temp != NULL)
    {
        cout << temp->id << "\t"
             << temp->name << "\t"
             << temp->salary << endl;

        temp = temp->next;
    }
}

void searchEmployee(Employee *head)
{
    int searchID;

    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->id == searchID)
        {
            cout << "\nEmployee Found!" << endl;
            cout << "Employee ID: " << temp->id << endl;
            cout << "Employee Name: " << temp->name << endl;
            cout << "Salary: " << temp->salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nEmployee not found!" << endl;
}


int main()
{
    Employee *head = NULL;
    int choice;

    do
    {
        cout << "\n\n===== EMPLOYEE MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertEmployee(head);
                break;

            case 2:
                displayEmployees(head);
                break;

            case 3:
                searchEmployee(head);
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
