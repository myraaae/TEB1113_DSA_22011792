// Umairah binti Mohamed Azhar
// 22011792

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
        this->prev_ptr = nullptr;
    }
};

class DoublyCircularLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            head->next_ptr = head;
            head->prev_ptr = head;
        } else {
            tail->next_ptr = new_node;
            new_node->prev_ptr = tail;
            new_node->next_ptr = head;
            head->prev_ptr = new_node;
            tail = new_node;
        }
    }

    void display_forward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head: " << head->name << ")" << endl;
    }

    void display_backward() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail;
        do {
            cout << current->name << " <- ";
            current = current->prev_ptr;
        } while (current != tail);
        cout << "(back to tail: " << tail->name << ")" << endl;
    }
};

int main() {
    cout << "Doubly Circular Linked List" << endl;
    DoublyCircularLinkedList list;

    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Alee");
    list.add_element("Hamza");

    cout << "Forward: ";
    list.display_forward();

    cout << "Backward: ";
    list.display_backward();

    return 0;
}
