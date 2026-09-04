#include <iostream>
#include <string>
using namespace std;

// Node structure for each team
struct Node {
    string team;
    Node* next;
};

// Function to add a team to the circular linked list
void addTeam(Node*& head, string teamName) {
    Node* newNode = new Node;
    newNode->team = teamName;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } 
    else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to display teams
void displayTeams(Node* head) {
    if (head == NULL) {
        cout << "No teams available.\n";
        return;
    }

    Node* temp = head;

    cout << "\nTeams in Round Robin order:\n";

    do {
        cout << temp->team << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to " << head->team << ")\n";
}

// Function to simulate Round Robin scheduling
void roundRobin(Node* head, int rounds) {
    if (head == NULL) {
        cout << "No teams available.\n";
        return;
    }

    Node* current = head;

    cout << "\n--- Round Robin Tournament ---\n";

    for (int i = 1; i <= rounds; i++) {
        cout << "\nRound " << i << ":\n";

        cout << "Match: " << current->team
             << " vs " << current->next->team << endl;

        // Move to the next team
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int n;
    string teamName;

    cout << "Enter number of teams: ";
    cin >> n;

    // Input teams
    for (int i = 0; i < n; i++) {
        cout << "Enter team " << i + 1 << " name: ";
        cin >> teamName;

        addTeam(head, teamName);
    }

    // Display circular linked list
    displayTeams(head);

    // Simulate round robin
    roundRobin(head, n);

    return 0;
}

