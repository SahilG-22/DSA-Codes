#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* head = NULL;

//Inserting at the beginning
void insertBegin(int val){
    Node* newNode = new Node;   //Creating the new node
    newNode->data = val;        //Setting the Data of the new node
    newNode->next = head;       //Pointing the node to the head as the insetion is at the beginning
    head = newNode;             //Updating the head of the linked list as the new node is now the head
}

//Insertion at End
void insertEnd(int val){
    Node* newNode = new Node;   //Creating the new node
    newNode->data = val;        //Setting the DAtta of the new node
    newNode->next = NULL;       //Poinitng the new node to null as the insertion is at the end

    if(head == NULL){
        head = newNode;         //If there are no elements already in the list insertion at last is basically the first node in that case
        return;
    }

    Node* temp = head;          //temp pointer to traverse to the last node of the list
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;       //connecting the new node to the last node of the list
}

//Insert at user defined Position (pos)
void insertPosition(int val, int pos) {
    Node* newNode = new Node();
    newNode->data = val;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBegin() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete by value
void deleteValue(int val) {
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
}

// Search element
void search(int key) {
    Node* temp = head;
    int pos = 1;

    while(temp != NULL) {
        if(temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found\n";
}

// Count nodes
void countNodes() {
    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total nodes: " << count << endl;
}

// Display list
void display() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, pos;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Value\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Count Nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertPosition(val, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteValue(val);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                search(val);
                break;

            case 8:
                display();
                break;

            case 9:
                countNodes();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 0);

    return 0;
}
