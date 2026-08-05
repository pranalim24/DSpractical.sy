#include <iostream>
#include <cstdlib>
using namespace std;     //single doubly linked list

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

int main()
{
    Node *newnode = (Node *)malloc(sizeof(Node));

    newnode->data = 10;
    newnode->prev = NULL;
    newnode->next = NULL;

	cout<<"Single Doubly Linked List"<<endl;
    cout << "NULL -> " << newnode->data << " -> NULL" << endl;

    free(newnode);

    return 0;
}
