// Small utility: find length of the largest subarray with sum 0
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// returns length of the largest subarray whose elements sum to 0
int largest0SumSubarray(vector<int>& nums) {
    unordered_map<int, int> m; // map: prefix sum -> earliest index
    int sum = 0; // running prefix sum
    int len = 0; // best length found so far

    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j]; // include current element

        // case 1: sum from 0 to j is zero
        if (sum == 0) {
            len = max(len, j + 1);
        }
        
        if (m.count(sum)) {
            int currLen = j - m[sum]; // length between stored index and current
            len = max(len, currLen); // update best
        }
        else {
            m[sum] = j; // store first occurrence of this prefix sum
        }
    }
    return len;
}

int main() {
    // example input
    vector<int> nums = { 15, -2, 2, -8, 1, 7, 10 };

    // print result
    cout << "Largest 0 Sum Subarray: " << largest0SumSubarray(nums) << endl;
}