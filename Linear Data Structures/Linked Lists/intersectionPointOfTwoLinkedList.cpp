#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node* &head, int val) {
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

// Display list
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Create intersection
void createIntersection(Node* head1, Node* head2, int pos) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    for(int i = 1; i < pos; i++)
        temp1 = temp1->next;

    while(temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;
}

// Find intersection point
Node* findIntersection(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;

    while(p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2, val, pos;

    cout << "Enter number of nodes in List 1: ";
    cin >> n1;
    cout << "Enter elements:\n";
    for(int i = 0; i < n1; i++) {
        cin >> val;
        insert(head1, val);
    }

    cout << "Enter number of nodes in List 2: ";
    cin >> n2;
    cout << "Enter elements:\n";
    for(int i = 0; i < n2; i++) {
        cin >> val;
        insert(head2, val);
    }

    cout << "Enter position in List1 where intersection should occur (0 for none): ";
    cin >> pos;

    if(pos > 0)
        createIntersection(head1, head2, pos);

    Node* result = findIntersection(head1, head2);

    if(result != NULL)
        cout << "Intersection point data: " << result->data << endl;
    else
        cout << "No intersection found\n";

    return 0;
}