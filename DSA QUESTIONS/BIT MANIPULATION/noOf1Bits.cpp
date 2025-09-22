#include<iostream>
using namespace std;

int oneBits(int num) {
    int sum = 0;

    if (num <= 0) return 0;
    while (num > 0) {
        sum += num & 1;
        num = num >> 1;
    }
    return sum;
}

int main() {
    int num;

    cout << "Enter a Number: ";
    cin >> num;

    cout << "Number of 1 Bits in " << num << ": " << oneBits(num) << endl;

    return 0;
}