#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> countDistinct(vector<int>& nums) {
    // Use unordered_set to keep only one copy of each value (O(1) average insert)
    unordered_set<int> s;

    for (int val : nums) {
        s.insert(val); // insert each value; duplicates ignored by the set
    }

    // Move unique values from the set into a vector to return
    vector<int> ans;
    ans.reserve(s.size()); // reserve space for a small performance gain
    for (int val : s) {
        ans.push_back(val);
    }

    return ans;
}

int main() {
    // Example input (contains duplicates)
    vector<int> nums = { 4, 3, 2, 5, 6, 7, 3, 4, 2, 1 };

    // Get distinct elements
    vector<int> ans = countDistinct(nums);

    // Print the distinct values (order from unordered_set is unspecified)
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}