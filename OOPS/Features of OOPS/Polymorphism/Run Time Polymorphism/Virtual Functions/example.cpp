#include<iostream>
using namespace std;

class Parent {
public:
    virtual void name() {
        cout << "My name is 'Parent'\n";
    }
};

class Child : public Parent {
public:
    void name() {
        cout << "My name is 'Child'\n";
    }
};

int main() {
    Child c1;
    Parent* ptr;

    ptr = &c1;
    ptr->name(); 
    return 0;
}