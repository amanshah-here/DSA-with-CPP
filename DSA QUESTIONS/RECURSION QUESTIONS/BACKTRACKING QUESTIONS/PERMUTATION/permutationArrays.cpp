#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> permutation(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {  //base case
    if (index == nums.size()) {
        ans.push_back(output);      //pushing the current output into ans.
        return {};
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1e9) continue;   //skip if the current value is -ve infinity.

        int val = nums[i];
        output.push_back(val);
        nums[i] = 1e9;      // assigning - ve infinity to current index to keep track of which element is pushed already.

        permutation(nums, output, index + 1, ans);  //recursive call for the next index.
        output.pop_back();  //! BACKTRACKING: •Emptying the output
        nums[i] = val;      //! •Reassigning the value back.
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<int> output;
    vector<vector<int>> ans;

    permutation(nums, output, 0, ans);
    print(ans);
    return 0;
}