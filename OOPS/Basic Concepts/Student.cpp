#include<iostream>
#include<string>
using namespace std;

class Student {
    //properties
    string name;
    float cgpa;

public:
    
    //methods
    void getInput() {
        cout << "Enter Student's Name: ";
        getline(cin,name);
        cout << "Enter Student's CGPA: ";
        cin >> cgpa;
    }

    void print() {
        cout << "\nStudent's Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1; //object
    cout << "Size of Object: " << sizeof(s1) << endl;
    s1.getInput();
    s1.print();

    return 0;
}