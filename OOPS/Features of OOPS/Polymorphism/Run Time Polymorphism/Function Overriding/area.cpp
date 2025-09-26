#include<iostream>
using namespace std;
#define PI 3.14

class Area {
public:
    float ar;

    void area() {
        cout << "This is a function to calculate area.\n";
    }
};

class Circle : public Area {
public:
    void area(float r) {
        ar = 2 * PI * r;
        cout << "Area of Circle: " << ar <<" mtr. sq." <<endl;
    }
};

class Triangle : public Area {
public:
    void area(float base, float ht) {
        ar = 0.5 * base * ht;
        cout << "Area of Triangle: " << ar << " mtr. sq." << endl;
    }
};

class Rectangle : public Area {
public:
    void area(float len, float breadth) {
        ar = len * breadth;
        cout << "Area of Rectangle: " << ar << " mtr. sq." << endl;
    }
};

class Square : public Area {
public:
    void area(float side) {
        ar = side * side;
        cout << "Area of Square: " << ar << " mtr. sq." << endl;
    }
};

int main() {
    Circle c1;
    c1.area(4);

    Triangle t1;
    t1.area(10, 15);

    Rectangle r1;
    r1.area(4, 3);

    Square s1;
    s1.area(12);

    return 0;
}