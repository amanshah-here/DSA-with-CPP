#include<iostream>
using namespace std;

void oddOrEven(int n) {

    if (!(n & 1)) { //coverting all the bits except right most bit into 0 and then checking if the right most bit is 0 or not
        cout << "Even" << endl;
    }
    else {
        cout << "odd" << endl;
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    oddOrEven(n);

    return 0;
}