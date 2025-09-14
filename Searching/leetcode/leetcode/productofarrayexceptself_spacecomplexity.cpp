#include<iostream>
#include<vector>
using namespace std;

vector<int> product(vector<int>& nums){

     vector<int> ans(nums.size(), 1);
 
    //prefix
    for (int i = 1; i < nums.size();i++){
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    //suffix
    int suffix = 1;
    for (int j = nums.size() - 2; j >= 0;j--){
        suffix *= nums[j + 1];
        ans[j] *= suffix;
    }

    for (int i = 0; i < nums.size();i++){
        cout << ans[i] << " ";
    }
        return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    product(nums);
    return 0;
}