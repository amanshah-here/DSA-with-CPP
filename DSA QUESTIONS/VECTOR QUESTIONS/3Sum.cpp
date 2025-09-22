#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Question: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//TODO: Notice that the solution set must not contain duplicate triplets.

//Soln: using two pointer approach or an addition of two sum question 

vector <vector<int>> threeSum(vector<int>& nums) {

    if (nums.size() < 3) return {};

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); //sorting the vector.

    for (int i = 0; i < nums.size(); i++) { //fixing the first value.

        if (i > 0 && nums[i] == nums[i - 1]) continue;  //to prevent from the repeated numbers.

        int st = i + 1, end = nums.size() - 1;  //taking two pointers.

        while (st < end) {

            int sum = nums[i] + nums[st] + nums[end];

            if (sum > 0) {
                end--;
            }
            else if (sum < 0) {
                st++;
            }
            else {
                ans.push_back({ nums[i],nums[st],nums[end] });
                st++, end--;

                while (st < end && nums[st] == nums[st - 1]) {      //to prevent from the repeated numbers.
                    st++;
                }
            }

        }
    }
    return ans;
}

int main() {
    vector<int>nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ans = threeSum(nums);

    for (int i = 0;i < ans.size();i++) {
        cout << "{ ";
        for (int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " , ";
        }
        cout << " } , ";
    }

    return 0;
}