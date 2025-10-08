#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void changearr(vector<int>& arr, int n, int i) {
    if (i == n) {   //! Base case
        printarr(arr, n);
        return;
    }
    arr[i] = i + 1;
    changearr(arr, n, i + 1);   //* recursive call
    arr[i] -= 2;    //? backtrack
}
int main() {
    vector<int> arr(5, 0);
    int n = 5, i = 0;
    changearr(arr, n, i);
    printarr(arr, n);
    return 0;
}