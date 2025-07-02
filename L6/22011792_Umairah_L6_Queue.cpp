// Umairah binti Mohamed Azhar
// 22011792

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // add new node at the end
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
        }
    }

    void display_queue() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next_ptr;
        cout << "Dequeued: " << temp->name << endl;
        delete temp;
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
