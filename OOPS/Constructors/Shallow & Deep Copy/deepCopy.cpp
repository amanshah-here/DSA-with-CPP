#include<iostream>
#include<string>
using namespace std;

class Car {
public:
    string name;
    string color;
    int* mileage;

    //parameterized constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
        mileage = new int;
        *mileage = 20;
    }
    //copy constructor
    Car(Car& original) {
        cout << "Copying original to new...\n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }

};

int main() {
    Car c1("Mercedes", "Blue");

    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;

    *c2.mileage = 10;
    cout << *c1.mileage << endl;
    return 0;
}