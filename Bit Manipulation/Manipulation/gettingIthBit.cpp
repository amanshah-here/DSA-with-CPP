#include<iostream>
using namespace std;

int getIthBit(int num, int pos) {
    int bitMask = (1 << pos);

    if (!(num & bitMask)) {
        return 0;
    }
    else {
        return 1;
    }
}
int main() {
    int num, bit;
    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter the Position of Bit: ";
    cin >> bit;

    

    cout << "Bit at " << bit << " Position: " << getIthBit(num,bit) << endl;

    return 0;
}