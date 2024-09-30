#include<iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

class Queue {
    int front, rear;
    int arr[MAX];
    
public:
    Queue() { // Constructor to initialize front and rear
        front = -1;
        rear = -1;
    }
    
    void push(int val) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot enqueue " << val << " into the queue.\n";
        } else {
            if (front == -1) front = 0; // Set front if first element is added
            rear++;
            arr[rear] = val;
            cout << val << " added to the queue.\n";
        }
    }
    
    void pop() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No element to dequeue.\n";
        } else {
            cout << arr[front] << " dequeued from the queue.\n";
            front++;
        }
    }
    
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Queue elements are:\n";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Queue q;
    int choice, value;
    
    while (true) {
        cout << "\nARJUN A (26)\nMenu:\n1. Push (Enqueue)\n2. Pop (Dequeue)\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to push (enqueue): ";
                cin >> value;
                q.push(value);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.display();
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
