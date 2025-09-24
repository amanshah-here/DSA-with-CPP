#include<iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eats\n";
    }

    void breathe() {
        cout << "Breathes\n";
    }
};

class Bird :public Animal {
public:
    void fly() {
        cout << "Birds can fly.\n";
    }
};

class Fish : public Animal {
public:
    void swim() {
        cout << "Fish can swim.\n";
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "Mammals can walk.\n";
    }
};

int main() {
    Bird b1;
    b1.eat();
    b1.breathe();
    b1.fly();

    Fish f1;
    f1.eat();
    f1.breathe();
    f1.swim();

    Mammal m1;
    m1.eat();
    m1.breathe();
    m1.walk();

    return 0;
}