#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    // Count occurrences of each value
    unordered_map<int, int> m;
    vector<int> ans;

    for (int val : nums) {
        // increment the count for val (insert if missing)
        if (m.count(val)) {
            m[val]++;
        }
        else {
            m[val] = 1;
        }
    }

    // Any element with frequency > n/3 is a valid answer
    for (auto& pair : m) {
        if (pair.second > nums.size() / 3)
            ans.push_back(pair.first);
    }

    return ans;
}

int main() {
    // Example input; main simply demonstrates the function
    vector<int> nums = { 1, 3, 2, 5, 1, 3, 1, 5, 1 };

    vector<int> ans = majorityElement(nums);

    // Print results separated by spaces
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
