#include<iostream>
#include<climits>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;  //if dividend and divisor are same then the quotient is 1.

    bool sign = true;   //a variable to keep track of sign of the number //! true means +ve , false means -ve

    //? Dealing with -ve numbers
    if (dividend >= 0 && divisor < 0) sign = false;
    if (dividend < 0 && divisor > 0) sign = false;

    long tempDividend = abs(long(dividend));  //taking the absolute value (removing sign)
    cout << tempDividend << endl;
    long tempDivisor = abs(long(divisor));    //taking the absolute value (removing sign)
    cout << tempDivisor << endl;
    long quotient = 0;

    while (tempDividend >= tempDivisor) {   
        int count = 0;
        while (tempDividend >= (tempDivisor << (count + 1))) {  //loop runs until the dividend is greater than or equal to divisor * 2^0, divisor * 2^1, divisor * 2^3.... 
            count++;    //stored how many time the loop runs basically the power of 2.
        }
        quotient += 1 << count; //adding 2^n, 2^n-1, 2^n-2......
        tempDividend -= (tempDivisor << count); //subtracting  quotient * 2^n.....

    }

    if (quotient == (1 << 31) && sign == true) {    //if quotient is greater than 2^31 - 1 then returning 2^31 - 1
        return INT_MAX;
    }
    if (quotient == (1 << 31) && sign == false) {   //if quotient is less than -2^31 then returning -2^31
        return INT_MIN;
    }
    return sign ? quotient : -quotient; //if sign is +ve returning quotient else -quotient
}

int main() {
    int dividend;
    int divisor;

    cout << "Enter Dividend: ";
    cin >> dividend;
    cout << "Enter Divisor: ";
    cin >> divisor;

    cout << dividend << " / " << divisor << ": " << divide(dividend, divisor) << endl;
    return 0;
}