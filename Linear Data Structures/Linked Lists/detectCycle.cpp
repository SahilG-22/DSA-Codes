#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list (safe display to avoid infinite loop)
void display() {
    Node* temp = head;
    int count = 0;

    while(temp != NULL && count < 20) { // limit display
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL\n";
}

// Create cycle (for testing)
void createCycle(int pos) {
    if(pos == 0) return;

    Node* temp = head;
    Node* join = NULL;
    int count = 1;

    while(temp->next != NULL) {
        if(count == pos)
            join = temp;
        temp = temp->next;
        count++;
    }

    temp->next = join; // create cycle
}

// Detect cycle using slow and fast pointer
void detectCycle() {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "Cycle detected in the linked list\n";
            return;
        }
    }

    cout << "No cycle in the linked list\n";
}

int main() {
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    cout << "Enter position to create cycle (0 for no cycle): ";
    cin >> pos;

    createCycle(pos);

    detectCycle();

    return 0;
}