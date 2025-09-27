#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>& arr, int target, int i) {
    int size = arr.size();  //base case
    if (i == size) return -1;
    if (arr[i] == target) return i;
    return firstOccurance(arr, target, i + 1);  //recursive call
}

int main() {
    vector<int> arr = { 1,2,7,3,4,5,5,6,7 };
    int target = 7;
    int i = 0;
    cout << firstOccurance(arr, target, i) << endl;
}