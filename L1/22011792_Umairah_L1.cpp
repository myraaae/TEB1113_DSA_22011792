// ID: 22011792
// Name: Umairah binti Mohamed Azhar

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id; string name, contact, email;
};

int main() {
    Student students[5];
    for (int i = 0; i < 5; i++) {
        cout<<"Info for Student #" << i + 1 << endl;
        cout<<"Enter ID: "; cin>>students[i].id;
        cin.ignore();
        cout<<"Enter name: "; getline(cin,students[i].name);
        cout<<"Enter contact: "; getline(cin,students[i].contact);
        cout<<"Enter email: "; getline(cin, students[i].email);
        cout<<endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent #" << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Contact: " << students[i].contact << endl;
        cout << "Email: " << students[i].email << endl << endl;
    }

    return 0;
}
