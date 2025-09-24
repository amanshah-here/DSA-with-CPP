#include<iostream>
#include<string>
using namespace std;

class Teacher {
public:
    int salary;
    string subject;

};

class Student {
public:
    int roll;
    float cgpa;
};

class TA : public Teacher, public Student {
public:
    string name;
};

int main() {
    TA t1;
    t1.name = "Aman Shah";
    t1.subject = "C++";
    t1.roll = 235031;
    t1.cgpa = 8.7;

    cout << t1.name << endl;
    cout << t1.subject << endl;
    cout << t1.roll << endl;
    cout << t1.cgpa << endl;

    return 0;
}