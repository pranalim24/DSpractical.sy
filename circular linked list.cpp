#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = 10;

    // Circular links
    newNode->next = newNode;
    newNode->prev = newNode;

   printf("Prev: %d  Data: %d  Next: %d", 
           newNode->prev->data, 
           newNode->data, 
           newNode->next->data);

    free(newNode);

    return 0;
    
}

//Since there is only one node, both prev and next point back to the same node itself.
