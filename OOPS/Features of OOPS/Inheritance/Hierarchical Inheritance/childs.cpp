#include<iostream>
#include<string>
using namespace std;

class Parents {
public:
    string name;
    int age;

    void earn() {
        cout << "Earns Money..\n";
    }
};

class Son : public Parents {
public:

    void about() {
        cout << "I am son..\n";
    }
};

class Daughter : public Parents {
public:
    void aboutme() {
        cout << "I am Daughter..\n";
    }
    };

int main() {
    Son s1;
    s1.name = "Ram";
    s1.age = 17;
    cout << s1.name << endl;
    cout << s1.age << endl;
    s1.earn();
    s1.about();

    cout << endl;

    Daughter d1;
    d1.name = "Shreevalli";
    d1.age = 10;
    cout << d1.name << endl;
    cout << d1.age << endl;
    d1.earn();
    d1.aboutme();

    return 0;
}
