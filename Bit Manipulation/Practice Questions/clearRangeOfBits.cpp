#include<iostream>
using namespace std;

int clearBits(int num, int lowerRange, int upperRange) {

    int a = (~0) << (upperRange + 1);   //creating a nums having only 0 as bits from 0 to upperlimit
    int b = (1 << lowerRange) - 1;      //creating a number that has 1 as bits only before the lowerlimit

    int bitMask = a | b;    //combining both a and b to get a number which have 0 as bits only from lowerlimit to upperlimit

    return num & bitMask;
}

int main() {
    int num, i, j;

    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter Lower Range: ";
    cin >> i;
    cout << "Enter Upper Range: ";
    cin >> j;
    
    cout << "Before Clearing Number: " << num << endl;
    cout << "After Clearing Number: " << clearBits(num, i, j) << endl;

    return 0;
}