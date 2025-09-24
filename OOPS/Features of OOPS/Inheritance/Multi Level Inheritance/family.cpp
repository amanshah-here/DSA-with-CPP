#include<iostream>
#include<string>
using namespace std;

class Grandfather {
public:
    string name;
    string age;

    void about() {
        cout << "This is a family.\n";
    }
};

class Father : public Grandfather {
public:

    void income() {
        cout << "Family's Income: $$$$$$\n";
    }
};

class Son : public Father {
public:
    void hobby() {
        cout << "Son's hobby is to play Games.";
    }
};

int main() {
    Son s1;
    s1.name = "Happy";
    s1.age = "8";
    cout << s1.name << endl;
    cout << s1.age << endl;
    s1.about();
    s1.income();
    s1.hobby();

    return 0;
}