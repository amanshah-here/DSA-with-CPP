#include<iostream>
using namespace std;

int tiling(int n) { //floor size is (2 x n).
    if (n == 0 || n == 1) return 1; //base case.

    //vertical tile placement.
    //int ans1 = tiling(n - 1);   //(2 x n - 1)

    //horizontal tile placement
    //int ans2 = tiling(n - 2);   //(2 x n - 2)

    return tiling(n - 1) + tiling(n - 2);
}

int main() {
    int n;
    cout << "Enter the size of floor: ";
    cin >> n;
    cout << "Total no of ways to place tiles: " << tiling(n) << endl;
    return 0;
}