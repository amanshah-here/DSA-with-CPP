#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
    if (index >= nums.size()) {   //base case.
        ans.push_back(output);
        return;
    }
    //Exclude term
    solve(nums, output, index + 1, ans);

    //Include term
    int currElement = nums[index];
    output.push_back(currElement);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subset(vector<int>& nums) {
    vector<int> output;//vector to store current subset.
    vector<vector<int>> ans;    //vector to store all the subset.
    int index = 0;
    solve(nums, output, index, ans);    //calling recursive Function
    return ans;
}

int main() {
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> ans = subset(nums);

    for (int i = 0;i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ",";
        cout << "], ";
    }
    return 0;
}