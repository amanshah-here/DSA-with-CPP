#include<iostream>
#include<string>
using namespace std;

class Bike {
    string name;
    string color;
public:
    Bike(string nameVal, string colorVal){ 
        cout << "constructor hs called" << endl;
        name = nameVal;
        color = colorVal;
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