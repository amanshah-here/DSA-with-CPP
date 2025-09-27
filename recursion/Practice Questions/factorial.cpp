#include<iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;   //base case.
    return n * factorial(n - 1);    //recursive call.
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout<<"Factorial of "<<n<<": " << factorial(n);
    return 0;
}