#include <iostream>
using namespace std;

// Structure for a doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert after a node with specific data
void insertAfterData(Node*& head, int afterValue, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with data " << afterValue << " not found!\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete the first node
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

// Function to delete the last node
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
}

// Function to delete a node with specific data
void deleteByData(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with data " << value << " not found!\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// Function to search for a node with specific data
void search(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with data " << value << " not found!\n";
    } else {
        cout << "Node with data " << value << " found!\n";
    }
}

// Function to display the list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function with menu-driven operations
int main() {
    Node* head = nullptr;
    int choice, value, afterValue;

    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert after a specific data\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete by Data\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter data after which to insert: ";
                cin >> afterValue;
                cout << "Enter value to insert: ";
                cin >> value;
                insertAfterData(head, afterValue, value);
                break;
            case 4:
                deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByData(head, value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;
            case 8:
                display(head);
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
}