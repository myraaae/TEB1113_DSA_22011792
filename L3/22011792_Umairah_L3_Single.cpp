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
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string target_name) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->name == target_name) {
                if (current == head) {
                    head = head->next_ptr;
                    delete current;
                } else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail) {
                        tail = prev;
                    }
                    delete current;
                }
                cout << "Deleted: " << target_name << endl;
                return;
            }
            prev = current;
            current = current->next_ptr;
        }

        cout << "Not found: " << target_name << endl;
    }
};

int main() {
    cout << "Singly Linked List" << endl;
    LinkedList list;

    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Alee");

    cout << "List: ";
    list.display_list();

    list.delete_by_value("Ahmed");

    cout << "After deleting 'Ahmed': ";
    list.display_list();

    return 0;
}
