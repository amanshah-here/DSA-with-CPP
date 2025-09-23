#include<iostream>
#include<string>
using namespace std;

class Car {
public:
    string name;
    string color;

    //parameterized constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
    }
    //copy constructor
    Car(Car& original) {
        cout << "Copying original to new...\n";
        name = original.name;
        color = original.color;
    }

};

int main() {
    Car c1("Mercedes", "Blue");

    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0; 
}