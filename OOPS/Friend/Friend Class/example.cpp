#include<iostream>
#include<string>
using namespace std;

class A {
    string secret = "Secret data";
    friend class B;
};

class B {   //friend class of A so it can access private and protected data
public:
    void showSecret(A& obj) {
        cout << obj.secret << endl;
    }
};

int main() {
    A a1;
    B b1;

    b1.showSecret(a1);
    return 0;
}