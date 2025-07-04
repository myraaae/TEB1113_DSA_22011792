// Umairah binti Mohamed Azhar
// 22011792

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; // maximum queue size
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Add a new item to the rear
    void enqueue(string name) {
        if (rear == SIZE - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = name;
    }

    // Remove the item at the front
    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        // If this was the last element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    // Display the queue from front to rear
    void display_queue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " -> ";
        }
        cout << "NULL" << endl;
    }

    bool is_empty() {
        return front == -1 || front > rear;
    }
};

int main() {
    cout << "Queue" << endl;
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Alee");

    cout << "Queue: ";
    q.display_queue();

    q.dequeue();

    cout << "After dequeueing: " << endl;
    q.display_queue();

    return 0;
}
