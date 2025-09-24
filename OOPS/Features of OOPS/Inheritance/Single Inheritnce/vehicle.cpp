#include<iostream>
#include<string>
using namespace std;

class Vehicle {
public:
    string color;
    string name;

    void speed(int speed) {
        cout << "Speed is " << speed << "KM/H.\n";
    }
    void mileage(int mileage) {
        cout << "Mileage is " << mileage << "KM/L.\n";
    }
};

class Car : public Vehicle {
public:
    string type;

    void start() {
        cout << "Starting....\n";
    }
};

int main() {
    Car c1;
    c1.name = "BMW M5";
    c1.color = "Black";
    c1.type = "Luxary";
    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << c1.type << endl;
    c1.start();
    c1.speed(190);
    c1.mileage(14);

    return 0;
}