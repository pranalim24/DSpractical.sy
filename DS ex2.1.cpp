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


void deleteEmployee(Employee *&head)
{
    int id;

    cout << "\nEnter Employee ID to delete: ";
    cin >> id;

    if (head == NULL)
    {
        cout << "\nList is empty!" << endl;
        return;
    }

    if (head->id == id)
  
    {
        Employee *temp = head;
        head = head->next;
        delete temp;

        cout << "\nEmployee deleted successfully!" << endl;
        return;
    }

    Employee *temp = head;

    while (temp->next != NULL && temp->next->id != id)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "\nEmployee not found!" << endl;
    }
    else
    {
        Employee *deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << "\nEmployee deleted successfully!" << endl;
    }
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


int main()
{
    Employee *head = NULL;
    int choice;

    do
    {
        cout << "\n\n===== EMPLOYEE MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employees" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertEmployee(head);
                break;

            case 2:
                deleteEmployee(head);
                break;

            case 3:
                displayEmployees(head);
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
