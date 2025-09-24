#include<iostream>
using namespace std;

class Animal {
public:

    void eat() {
        cout << "Eats..\n";
    }
    void breathe() {
        cout << "Breathes..\n";
    }
};

class Insects : public Animal {
public:
    void bite() {
        cout << "Bites..\n";
    }
};
class HouseFly : public Insects {
public:
    void apperance() {
        cout << "HouseFly is a tiny insect..\n";
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "Mammal can walk..\n";
    }
};
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog Barks..\n";
    }
};

int main() {
    HouseFly h1;
    h1.eat();
    h1.breathe();
    h1.bite();
    h1.apperance();

    cout << endl;

    Dog d1;
    d1.eat();
    d1.breathe();
    d1.walk();
    d1.bark();

    return 0;
}
