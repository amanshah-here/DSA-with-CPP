#include<iostream>
using namespace std;

int clearLastBits(int num, int bits) {
    int bitMask = (~0) << bits;

    return num & bitMask;
}

int main() {
    int num, bits;

    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter the Bits: ";
    cin >> bits;

    cout << "Before Clearing Number: " << num << endl;
    cout << "After Clearing Last " << bits << " Bits Number: " << clearLastBits(num, bits);

    return 0;
}