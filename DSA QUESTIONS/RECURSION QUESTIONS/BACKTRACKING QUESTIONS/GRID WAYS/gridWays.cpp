#include<iostream>
#include<vector>
using namespace std;

int ways(int row, int col, int n, int m) {
    if (row == n - 1 && col == m - 1) return 1;     //base case for destination.
    if (row >= n || col >= m) return 0;

    int rightVal = ways(row, col + 1, n, m);    //recursive call for moving RIGHT.

    int downVal = ways(row + 1, col, n, m);     //recursive call for moving DOWN.

    return rightVal + downVal;
} 

int main() {
    int n = 3;
    int m = 4;  //3 x 4
    cout << ways(0, 0, n, m) << endl;

    return 0;
}