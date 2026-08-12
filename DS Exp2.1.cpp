#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int Id;
    string Name;
    float Salary;
    Employee* next;
};

Employee* head = NULL;

// Function to insert an employee
void insert()
{
    Employee* newNode = new Employee;

    cout << "Enter Employee Id: ";
    cin >> newNode->Id;

    cout << "Enter Employee Name: ";
    cin >> newNode->Name;

    cout << "Enter Employee Salary: ";
    cin >> newNode->Salary;

    newNode->next = head;
    head = newNode;

    cout << "Employee Record Inserted Successfully.\n";
}

// Function to delete an employee
void deleteNode(int Id)
{
    if (head == NULL)
    {
        cout << "List Is Empty.\n";
        return;
    }

    Employee* temp = head;
    Employee* prev = NULL;

    // If the first node contains the ID
    if (head->Id == Id)
    {
        head = head->next;
        delete temp;

        cout << "Employee Record Deleted Successfully.\n";
        return;
    }

    // Search for the employee
    while (temp != NULL && temp->Id != Id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Employee not found
    if (temp == NULL)
    {
        cout << "Employee Record Not Found.\n";
        return;
    }

    // Remove the node
    prev->next = temp->next;
    delete temp;

    cout << "Employee Record Deleted Successfully.\n";
}

// Function to search an employee
void searchNode(int Id)
{
    if (head == NULL)
    {
        cout << "List Is Empty.\n";
        return;
    }

    Employee* temp = head;

    while (temp != NULL)
    {
        if (temp->Id == Id)
        {
            cout << "\nEmployee Found!\n";
            cout << "Employee Id: " << temp->Id << endl;
            cout << "Employee Name: " << temp->Name << endl;
            cout << "Employee Salary: " << temp->Salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Employee Record Not Found.\n";
}

// Function to display all employees
void display()
{
    if (head == NULL)
    {
        cout << "List Is Empty.\n";
        return;
    }

    Employee* temp = head;

    cout << "\n***** Employee Records *****\n";

    while (temp != NULL)
    {
        cout << "Employee Id: " << temp->Id << endl;
        cout << "Employee Name: " << temp->Name << endl;
        cout << "Employee Salary: " << temp->Salary << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

// Main function
int main()
{
    int choice, id;

    do
    {
        cout << "\n*** Employee Record Management ***\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employee Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                cout << "Enter Employee Id to Delete: ";
                cin >> id;
                deleteNode(id);
                break;

            case 3:
                cout << "Enter Employee Id to Search: ";
                cin >> id;
                searchNode(id);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "THANK-YOU.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0 ;
}
