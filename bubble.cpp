#include<iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    int temp;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n) {
    int minIndex, temp;
    for(int i=0; i<n-1; i++) {
        minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if(minIndex != i) {
            temp = a[minIndex];
            a[minIndex] = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    int n, choice, i;
    cout << "Enter the array size: ";
    cin >> n;
    int a[n];
    
    cout << "Enter array elements: ";
    for(i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << "ARJUN A (26)\nChoose sorting method:\n1. Bubble Sort\n2. Selection Sort\nEnter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        default:
            cout << "Invalid choice!";
            return 0;
    }

    cout << "After sorting: ";
    for(i=0; i<n; i++) {
        cout << "\n" << a[i];
    }

    return 0;
}

