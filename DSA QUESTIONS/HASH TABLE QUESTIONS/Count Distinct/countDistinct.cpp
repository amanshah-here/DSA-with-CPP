#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

// Count distinct integers in a vector using an unordered_set
// Input: vector<int>& nums - list of integers
// Output: int - number of unique elements
int countDistinct(vector<int>& nums) {
    unordered_set<int> s; // set stores unique values

    for (int val : nums) {
        s.insert(val); // insert each value (duplicates ignored)
    }

    return s.size(); // size of set = number of distinct elements
}

int main() {
    // example input
    vector<int> nums = { 4, 3, 2, 5, 6, 7, 3, 4, 2 ,1 };

    // print result
    cout << "Number of Distinct elements: " << countDistinct(nums) << endl;

    return 0;
}