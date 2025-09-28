#include<iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1;
    int halfPwr = power(x, n / 2);
    if (n % 2 == 0) return  halfPwr * halfPwr;  //if power is even;
    return x * halfPwr * halfPwr;   //if power is odd.
}

int main() {
    int num, pow;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the power: ";
    cin >> pow;

    cout << num << " to the power " << pow << ": " << power(num, pow) << endl;
    return 0;
}