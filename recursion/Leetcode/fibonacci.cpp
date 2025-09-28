#include<iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) return n;   //fibonacci of 0th term is 0 and fibonacci of 1st term is 1.
    return fibonacci(n - 1) + fibonacci(n - 2); //recursive call.
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << n << "th Fibonacci Term: " << fibonacci(n) << endl;
    return 0;
}