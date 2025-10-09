#include<iostream>
#include<vector>
using namespace std;

int ways(int row, int col, int n, int m,string ans) {
    if (row == n - 1 && col == m - 1) {     //base case for destination.
        cout << ans << "\n";
        return 1;
    }
        if (row >= n || col >= m) return 0;

    int rightVal = ways(row, col + 1, n, m, ans+"-R");    //recursive call for moving RIGHT.

    int downVal = ways(row + 1, col, n, m, ans+"-D");     //recursive call for moving DOWN.

    return rightVal + downVal;
}

int main() {
    int n = 3;
    int m = 3;  //3 x 3
    string ans;
    cout << ways(0, 0, n, m, ans) << endl;

    return 0;
}