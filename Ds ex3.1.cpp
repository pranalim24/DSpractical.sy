#include <iostream>
#include <string>
using namespace std;


struct Song
{
    string name;
    string artist;
    Song *prev;
    Song *next;
};


void addSong(Song *&head)
{
    Song *newSong = new Song;

    cout << "\nEnter Song Name: ";
    cin >> newSong->name;

    cout << "Enter Artist Name: ";
    cin >> newSong->artist;

    newSong->prev = NULL;
    newSong->next = NULL;

    
    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        Song *temp = head;

        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    cout << "\nSong added successfully!" << endl;
}


void deleteSong(Song *&head)
{
    string songName;

    cout << "\nEnter Song Name to Delete: ";
    cin >> songName;

    Song *temp = head;

    & temp->name != songName)
    {
        temp = temp->next;
    }

    
    if (temp == NULL)#include <iostream>
#include <string>
using namespace std;

// Structure for employee node
struct Employee
{
    int id;
    string name;
    float salary;
    Employee *next;
};

// Function to insert employee
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

// Function to display employees
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

// Function to search employee by ID
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

// Main function
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
    {
        cout << "\nSong not found!" << endl;
        return;
    }

   
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    delete temp;

    cout << "\nSong deleted successfully!" << endl;
}


void displayPlaylist(Song *head)
{
    if (head == NULL)
    {
        cout << "\nPlaylist is empty!" << endl;
        return;
    }

    Song *temp = head;

    cout << "\n===== MUSIC PLAYLIST =====" << endl;

    int count = 1;

    while (temp != NULL)
    {
        cout << count << ". "
             << temp->name
             << " - "
             << temp->artist << endl;

        temp = temp->next;
        count++;
    }
}


int main()
{
    Song *head = NULL;
    int choice;

    do
    {
        cout << "\n\n===== MUSIC PLAYLIST =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Display Playlist" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addSong(head);
                break;

            case 2:
                deleteSong(head);
                break;

            case 3:
                displayPlaylist(head);
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
