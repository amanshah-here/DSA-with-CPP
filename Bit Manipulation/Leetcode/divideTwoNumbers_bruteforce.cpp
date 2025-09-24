#include<iostream>
using namespace std;

int divide(int dividend, int divisor) {
    int sum = 0;
    int count = 0;
    while (sum + divisor <= dividend) {
        count += 1;
        sum += divisor;
    }
    return count;
}

int main() {
    int dividend = 20;
    int divisor = 3;

    cout << divide(dividend, divisor) << endl;

    return 0;
}