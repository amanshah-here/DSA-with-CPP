#include<iostream>
#include<vector>
using namespace std;

vector<int> product(vector<int> & nums){
    vector<int> ans(nums.size(), 1);

    for (int i = 0; i < nums.size();i++){
        for (int j = 0; j < nums.size();j++){
            if(i!=j){
                ans[i] *= nums[j];
            }

        }
    }
    for (int i = 0; i < nums.size();i++){
        cout << ans[i] << endl;
    }
        return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
         product(nums);
    return 0;
}