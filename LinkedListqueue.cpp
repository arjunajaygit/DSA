#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    
    // Constructor to initialize front and rear
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation to insert an element at the end of the queue
    void enqueue(int val) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap overflow! Cannot enqueue " << val << " into the queue.\n";
            return;
        }
        newNode->data = val;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " added to the queue.\n";
    }

    // Dequeue operation to remove the front element from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow! No element to dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << temp->data << " removed from the queue.\n";
        delete temp;
    }

    // Display the elements of the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements are:\n";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, value;
    
    while (true) {
        cout << "\nARJUN A (26)\n Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
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

