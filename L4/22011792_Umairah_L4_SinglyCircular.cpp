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

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // add new node at the end
    void add_element(string name) {
        Node* new_node = new Node(name); //temporary

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            tail->next_ptr = head; //points to the head itself (if only 1 value, it circles back to itself)
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head; 
        }
    }

    void display_list() {
        Node* current = head;
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
        do {
        cout << current->name << " -> ";
        current = current->next_ptr;
    } while (current != head);
    cout << head->name << endl;
    }
};

int main() {
    cout <<  "Circular Linked List" << endl;
    LinkedList list;

    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Alee");
    list.add_element("Hamza");

    cout << "List: ";
    list.display_list();

    return 0;
}
