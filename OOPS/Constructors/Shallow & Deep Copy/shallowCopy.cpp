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
        mileage = new int;  //dynamic allocation
        *mileage = 20;
    }

};

int main() {
    Car c1("Mercedes Benz", "Blue");

    /*
    shallow copy copies references to the original dynamic memory,

    shallow copy doesn't creates an another new copy for itself instead it starts pointing to the same memory,

    so any changes to the copy also changes the original variables,

    this problem arrises for dynamic memories.
*/
    
    Car c2(c1); //default copy constructor is called 
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl<<endl;
    *c2.mileage = 10;

    cout << *c1.mileage << endl;
    return 0;
}