#include<iostream>
#include<string>
using namespace std;

class Father {
public:
    string name;
    string age;

    void salary() {
        cout << "Father's Salary: $$$$$\n";
    }
};

class Mother {
public:

    void love() {
        cout << "Mother Loves Childs..\n";
    }
};

class Son : public Father, public Mother {
public:
    void happiness() {
        cout << "Son stays happy with parents..";
    }
};

int main() {
    Son s;
    s.name = "Sohan";
    s.age = "12";
    cout << s.name << endl;
    cout << s.age << endl;
    s.salary();
    s.love();
    s.happiness();

    return 0;
}