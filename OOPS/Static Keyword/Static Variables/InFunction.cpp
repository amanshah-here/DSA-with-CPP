#include<iostream>
using namespace std;

void counter(){
    int count = 0;
    count++;
    cout << "count: " << count << endl;
}

void counter2() {
    static int count = 0;
    count++;
    cout << "count: " << count << endl;
}

int main() {
    cout << "without static variable: \n";
    counter();
    counter();
    counter();

    cout << "With a static variable: \n";
    counter2();
    counter2();
    counter2();

    return 0;
}