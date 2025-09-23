#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& arr) {
    int ans = 0;
    for (int element : arr) {
        ans ^= element; //xor of same number is zero
    }
    return ans;
}

int main() {
    vector<int> arr = { 1,2,2,1,3,4,3 };
    vector<int> arr2 = { 1 };

    cout << "Single Element: " << singleNumber(arr) << endl;
    cout << "Single Element: " << singleNumber(arr2) << endl;

    return 0;
}