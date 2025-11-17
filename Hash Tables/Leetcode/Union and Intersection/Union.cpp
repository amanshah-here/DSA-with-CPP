#include<iostream>
#include<unordered_set>
#include<vector>

// Simple program to compute the union of two integer arrays
// Uses an unordered_set to collect unique elements, then
// returns them in a vector (order will be unspecified).
using namespace std;

vector<int> getUnion(vector<int>& arr1, vector<int>& arr2) {
    // Use a hash set to keep only unique values
    unordered_set<int> s;

    // Insert all elements from first array
    for (int val : arr1) {
        s.insert(val);
    }

    // Insert all elements from second array (duplicates ignored by set)
    for (int val : arr2) {
        s.insert(val);
    }

    // Move unique elements from set to vector to return
    vector<int> ans;
    for (int val : s) {
        ans.push_back(val);
    }

    return ans;
}

int main() {
    // Example input arrays
    vector<int> arr1 = { 7, 3, 9 };
    vector<int> arr2 = { 6, 3, 9, 2, 9, 4 };

    // Get union and print results (order not guaranteed)
    vector<int> ans = getUnion(arr1, arr2);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}