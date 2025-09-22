#include<iostream>
using namespace std;

int setIthBit(int num, int pos) {
    int bitMask = 1 << pos;

    return num | bitMask;
}

int main() {
    int num, bit;
    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter the Position of Bit: ";
    cin >> bit;

    cout << "Before setting Number: " << num << endl;

    cout << "After Setting Number: " << setIthBit(num, bit) << endl;

    return 0;
}