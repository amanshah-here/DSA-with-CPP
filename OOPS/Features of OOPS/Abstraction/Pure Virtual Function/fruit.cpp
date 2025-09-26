#include<iostream>
using namespace std;

class Fruit {
public:
    virtual void detail() = 0;
};

class Apple : public Fruit {
public:
    void detail() {
        cout << "This is a red colored fruit named Apple.\n";
    }
};

class Mango : public Fruit {
public:
    void detail() {
        cout << "Mango is the king of fruits.\n";
    }
};

class Banana : public Fruit {
public:
    void detail() {
        cout << "Banana is a rich in iron fruit.\n";
    }
};

int main() {
    Apple a1;
    a1.detail();

    Mango m1;
    m1.detail();

    Banana b1;
    b1.detail();

    return 0;
}