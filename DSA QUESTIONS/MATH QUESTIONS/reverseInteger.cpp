#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int n) {
    int rem;
    long long rev = 0;
    int n1 = n;

    while (n1 != 0) {
        rem = n1 % 10;
        rev = rev * 10 + rem;
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        n1 /= 10;
    }
    return rev;
}

int main() {
    int num;
    cout << "Enter a Number: ";
    cin >> num;

    cout << "Reverse of " << num << ": " << reverse(num) << endl;
    return 0;
}