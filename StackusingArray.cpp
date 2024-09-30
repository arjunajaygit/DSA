#include<iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class Stack {
    int top;
    int arr[MAX];
    
public:
    Stack() { // Constructor to initialize top
        top = -1;
    }
    
    void push(int val) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << val << " into the stack.\n";
        } else {
            top++;
            arr[top] = val;
            cout << val << " pushed into the stack.\n";
        }
    }
    
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! No element to pop.\n";
        } else {
            cout << arr[top] << " popped from the stack.\n";
            top--;
        }
    }
    
    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack s;
    int choice, value;
    
    while (true) {
        cout << "\nARJUN A (26)\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
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
