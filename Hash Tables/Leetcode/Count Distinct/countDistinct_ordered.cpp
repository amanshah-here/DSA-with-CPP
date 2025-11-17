#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> countDistinct(vector<int>& nums) {
    set<int> s; // ordered set: keeps unique elements in ascending order

    // insert all values into the set (duplicates are ignored)
    for (int val : nums) {
        s.insert(val);
    }

    // move the unique, ordered values into a result vector
    vector<int> ans;
    for (int val : s) {
        ans.push_back(val);
    }

    return ans;
}

int main() {
    // sample input with duplicates
    vector<int> nums = { 4, 3, 2, 5, 6, 7, 3, 4, 2, 1 };

    // compute distinct, ordered values
    vector<int> ans = countDistinct(nums);

    // print result: expected to show each number once in ascending order
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}