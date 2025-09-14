#include<iostream>
#include<vector>
using namespace std;

vector<int> product(vector<int>& nums){
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);
    vector<int> ans(nums.size(), 1);
    //prefix
    for (int i = 1; i < nums.size();i++){
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    //suffix
    for (int j = nums.size() - 2; j >= 0;j--){
        suffix[j] = suffix[j + 1] * nums[j + 1];
    }
    //answer
    for (int i = 0; i < nums.size();i++){
        ans[i] = prefix[i] * suffix[i];
    }
    for (int i = 0; i < nums.size();i++){
        cout << ans[i] << " ";
    }
        return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    product(nums);

}