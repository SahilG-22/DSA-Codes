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

// Create cycle for testing
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

    temp->next = join;
}

// Find length of cycle
void cycleLength() {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            int length = 1;
            Node* temp = slow->next;

            while(temp != slow) {
                length++;
                temp = temp->next;
            }

            cout << "Cycle detected\n";
            cout << "Length of cycle: " << length << endl;
            return;
        }
    }

    cout << "No cycle present\n";
}

int main() {
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    cout << "Enter position to create cycle (0 for no cycle): ";
    cin >> pos;

    createCycle(pos);

    cycleLength();

    return 0;
}