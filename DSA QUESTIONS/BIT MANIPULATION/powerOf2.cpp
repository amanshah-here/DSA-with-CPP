#include<iostream>
using namespace std;

bool powerOf2(int num) {
    if (!(num & (num-1))) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    powerOf2(num) ? cout << "Yess! " << num << " is a Power of 2." << endl : cout << "No! " << num << " isn't a Power of 2" << endl;
    return 0;
}