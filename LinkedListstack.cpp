#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
    
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Push operation to insert an element at the top of the stack
    void push(int val) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap overflow! Cannot push " << val << " into the stack.\n";
            return;
        }
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << val << " pushed into the stack.\n";
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow! No element to pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from the stack.\n";
        delete temp;
    }

    // Display the elements of the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements are:\n";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n ARJUN A (26)\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
