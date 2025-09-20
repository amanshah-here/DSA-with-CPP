#include<iostream>
#include<vector>
using namespace std;

//Problem Statement: You have a set of integers , which originally contains all the numbers from 1 to n. Unfortunately, due to some error,one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number

//TODO: Find the number that occurs twice and the number that is missing and return them in the form of an array.

//soln: using an extra vector to store the count of numbers in the given set and checking if the count is one or not.

vector<int> findErrorNums(vector<int>& nums) {
    
    vector<int> ans(nums.size() + 1, 0);
    int repeated = 0, missing = 0;

    for (int i = 0;i < nums.size(); i++) {  //storing the count of numbers in the given set.
        ans[nums[i]]++;
    }

    for (int i = 1;i < ans.size(); i++) {
        if (ans[i] == 2) repeated = i;  // checking if the count of any number is equal to 2 meaning it is twice in the set.
        if (ans[i] == 0) missing = i;   // checking if the count of any number is equal to 0 meaning it is missing in the set.
    }

    return{ repeated,missing };
}

int main() {
    vector<int> nums = { 1,2,3,3,5 };

    vector<int> ans = findErrorNums(nums);

    cout << ans[0] << " , " << ans[1] << endl;

    return 0;
}