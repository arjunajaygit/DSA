#include<iostream>
using namespace std;

#define SIZE 5 // Define the size of the circular queue

class CircularQueue {
    int front, rear;
    int arr[SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Insert element into the queue
    void insert(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
            cout << "Queue Overflow\n";
            return;
        } else if (front == -1) { // First element insertion
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
        cout << "Inserted: " << value << endl;
    }

    // Delete element from the queue
    void deleteElement() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        int data = arr[front];
        arr[front] = -1;
        if (front == rear) { // Only one element in the queue
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << "Deleted: " << data << endl;
    }

    // Display the queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.display();
    q.deleteElement();
    q.display();
    return 0;
}