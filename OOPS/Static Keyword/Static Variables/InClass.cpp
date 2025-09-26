#include<iostream>
using namespace std;

class Example {
public:
    int x = 0;
};

class Example2 {
public:
    static int x;
};
int Example2::x = 0;

int main() {
    Example e1;
    Example e2;
    Example e3;
    cout << "Normal variables..\n";
    cout << e1.x++ << endl;
    cout << e2.x++ << endl;

    Example2 eg1;
    Example2 eg2;
    Example2 eg3;
    cout << "Static variable..\n";
    cout << eg1.x++ << endl;
    cout << eg2.x++ << endl;
    cout << eg3.x++ << endl;
    return 0;
}