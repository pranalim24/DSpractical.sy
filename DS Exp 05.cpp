#include <iostream>
#include <string>
using namespace std;

#define MAX 10

// ================= ARRAY STACK =================

class ArrayStack {
    string pages[MAX];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(string page) {
        if (top == MAX - 1) {
            cout << "Array Stack is full!\n";
        } else {
            top++;
            pages[top] = page;
            cout << "Visited: " << page << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No previous page available!\n";
        } else {
            cout << "Going back from: " << pages[top] << endl;
            top--;

            if (top >= 0)
                cout << "Current page: " << pages[top] << endl;
            else
                cout << "No page available.\n";
        }
    }

    void display() {
        if (top == -1) {
            cout << "History is empty.\n";
            return;
        }

        cout << "\nBrowser History (Array Stack):\n";

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }
};


// ================= LINKED LIST STACK =================

struct Node {
    string page;
    Node* next;
};

class LinkedStack {
    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    void push(string page) {
        Node* newNode = new Node;

        newNode->page = page;
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "No previous page available!\n";
        } else {
            Node* temp = top;

            cout << "Going back from: " << top->page << endl;

            top = top->next;

            delete temp;

            if (top != NULL)
                cout << "Current page: " << top->page << endl;
            else
                cout << "No page available.\n";
        }
    }

    void display() {
        if (top == NULL) {
            cout << "History is empty.\n";
            return;
        }

        Node* temp = top;

        cout << "\nBrowser History (Linked List Stack):\n";

        while (temp != NULL) {
            cout << temp->page << endl;
            temp = temp->next;
        }
    }
};


// ================= MAIN FUNCTION =================

int main() {
    ArrayStack arrayStack;
    LinkedStack linkedStack;

    int choice;
    string page;

    do {
        cout << "\n====================================\n";
        cout << "     BROWSER BACKTRACKING SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Visit Page (Array Stack)\n";
        cout << "2. Back (Array Stack)\n";
        cout << "3. Display History (Array Stack)\n";
        cout << "\n";
        cout << "4. Visit Page (Linked List Stack)\n";
        cout << "5. Back (Linked List Stack)\n";
        cout << "6. Display History (Linked List Stack)\n";
        cout << "\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            // Array Stack
            case 1:
                cout << "Enter website name: ";
                cin >> page;
                arrayStack.push(page);
                break;

            case 2:
                arrayStack.pop();
                break;

            case 3:
                arrayStack.display();
                break;

            // Linked List Stack
            case 4:
                cout << "Enter website name: ";
                cin >> page;
                linkedStack.push(page);
                break;

            case 5:
                linkedStack.pop();
                break;

            case 6:
                linkedStack.display();
                break;

            case 7:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}

