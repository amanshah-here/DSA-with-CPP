#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int ways(int n, int m) {
    int ans = factorial((n - 1) + (m - 1)) / (factorial(n - 1) * factorial(m - 1));

    return ans;
}

int main() {
    int n = 3;
    int m = 4;

    cout << "Total no of ways to reach destination: " << ways(n, m) << endl;

    return 0;
}