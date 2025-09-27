#include<iostream>
using namespace std;

void decreasing(int n) {
    if (n == 0) {   //base case.
        return;
    }
    cout << n << " ";   //printing the number before calling for the smaller number.
    decreasing(n - 1);  //recursive call.
}

int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    decreasing(n);
    return 0;
}
