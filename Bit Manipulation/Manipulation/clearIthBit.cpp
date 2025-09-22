#include<iostream>
using namespace std;

int clearIthBit(int num, int pos) {
    int bitMask = ~(1 << pos);

    return num & bitMask;
}

int main() {
    int num, bit;
    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter the Position of Bit: ";
    cin >> bit;

    cout << "Before Clearing Number: " << num << endl;

    cout << "After Clearing Number: " << clearIthBit(num, bit) << endl;

    

    return 0;
}