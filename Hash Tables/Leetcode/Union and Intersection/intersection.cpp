#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

// Find common elements between two arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Store all elements from first array in a set
    unordered_set<int> s;
    for (int val : nums1) {
        s.insert(val);
    }

    // Check which elements from second array exist in the set
    vector<int> ans;
    for (int val : nums2) {
        if (s.find(val) != s.end()) {
            ans.push_back(val);
            s.erase(val);  // Remove to avoid duplicates
        }
    }
    return ans;
}

int main() {
    // Test arrays
    vector<int> arr1 = { 7, 3, 9 };
    vector<int> arr2 = { 6, 3, 9, 2, 9, 4 };

    // Find and print intersection
    vector<int> ans = intersection(arr1, arr2);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}