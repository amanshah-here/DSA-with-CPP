#include<iostream>
#include<string>
using namespace std;

class Bike {
    string name;
    string color;
public:
    
    Bike(string name, string color) {
        cout << "constructor hs called" << endl;
        this->name = name;  //this is pointing to the name attribute of current object
        this->color = color;    //this is pointing to the color attribute of current object
    }

    //getter

    string getname() {
        return name;
    }

    string getcolor() {
        return color;
    }
};

int main() {
    Bike b1("Kawasaki", "Black");

    cout << "Bike's name: " << b1.getname() << endl;
    cout << "Color: " << b1.getcolor() << endl;

    return 0;
}