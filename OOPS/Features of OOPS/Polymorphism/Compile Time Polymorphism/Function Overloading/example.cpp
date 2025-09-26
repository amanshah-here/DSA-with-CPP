#include<iostream>
#include<string>
using namespace std;

class Print {
public:
    void show(int num) {
        cout <<"Int: "<< num << endl;
    }                           //* function overloading different functions with same name but different parameter
    void show(string str) {
        cout <<"String: "<< str << endl;
    }
};

int main() {
    Print obj1;
    obj1.show(20);
    obj1.show("Hello World");
    return 0;
}