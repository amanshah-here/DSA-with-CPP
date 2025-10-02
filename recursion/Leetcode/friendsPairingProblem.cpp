#include<iostream>
#include<vector>
using namespace std;

int possiblePairs(int n) {
    if (n == 1 || n == 2) return n; //base case.
    //if left single then remaining = possiblePairs(n - 1).
    //for any one of all total no possible pairs are (n - 1).
    //if paired then remaining = possiblePairs(n -2).
    //so the total ways if paired = (n - 1) * possiblePairs(n - 2).
    //total number of ways to pair friends = single + paired.
    return possiblePairs(n - 1) + (n - 1) * possiblePairs(n - 2);
}

int main() {
    int n;
    cout << "Enter no of Friends: ";
    cin >> n;

    cout << "Total no of ways to pair friends: " << possiblePairs(n) << endl;
    return 0;
}