#include<iostream>
#include<vector>
using namespace std;

int lastOccurance(vector<int>& arr, int target, int i) {
    if (i < 0) return -1;   //base case.
    if (arr[i] == target) return i;
    return lastOccurance(arr, target, i - 1);   //recursive call.
}

int main() {
    vector<int> arr = { 1,2,3,4,3,5,6 };
    int i = arr.size() - 1;
    int target = 3;
    cout << lastOccurance(arr, target, i);
    return 0;
}