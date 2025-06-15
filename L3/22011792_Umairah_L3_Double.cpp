// Umairah binti Mohamed Azhar
// 22011792

#include <iostream>
#include <string>
using namespace std;

class DoubleNode {
public:
    string name;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoubleNode* head;
    DoubleNode* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        DoubleNode* new_node = new DoubleNode(name);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void display_list() {
        DoubleNode* current = head;
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string target_name) {
        DoubleNode* current = head;

        while (current != nullptr) {
            if (current->name == target_name) {
                if (current == head) {
                    head = head->next;
                    if (head != nullptr) head->prev = nullptr;
                    else tail = nullptr; // list became empty
                } else if (current == tail) {
                    tail = tail->prev;
                    if (tail != nullptr) tail->next = nullptr;
                    else head = nullptr; // list became empty
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                cout << "Deleted: " << target_name << endl;
                return;
            }

            current = current->next;
        }

        cout << "Not found: " << target_name << endl;
    }
};

int main() {
    DoublyLinkedList dlist;

    dlist.add_element("Ali");
    dlist.add_element("Ahmed");
    dlist.add_element("Alee");

    cout << "Doubly Linked List: ";
    dlist.display_list();

    dlist.delete_by_value("Ahmed");

    cout << "After deleting 'Ahmed': ";
    dlist.display_list();

    return 0;
}
