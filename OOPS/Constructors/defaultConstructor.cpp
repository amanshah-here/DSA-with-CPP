#include<iostream>
#include<string>
using namespace std;

class Car {
    string name;
    string color;
public:
    Car() {
        cout << "Constructor is called. object being created.." << endl;
    }
    void start() {
        cout << "Car has started..." << endl;
    }
    void stop() {
        cout << "Car has stopped..." << endl;
    }
};

int main() {
    Car c1;

    return 0;
}