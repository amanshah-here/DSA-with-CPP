#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Function to find two numbers that sum to target
// Returns indices of the two numbers, or {-1, -1} if not found
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;  // Store number and its index

    for (int i = 0; i < nums.size(); i++) {
        int tar = target - nums[i];  // Calculate complement

        // Check if complement exists in map
        if (m.count(tar)) {
            return { m[tar], i };  // Return indices of the pair
        }

        m[nums[i]] = i;  // Store current number and index
    }

    return { -1, -1 };  // No pair found
}

int main() {
    vector<int> nums = { 1, 2, 7, 11, 15, 5, 9 };  // Array of numbers

    int target = 16;  // Target sum

    vector<int> ans = twoSum(nums, target);  // Find the pair

    cout << "(" << ans[0] << ", " << ans[1] << ")\n";  // Print result indices
    return 0;
}