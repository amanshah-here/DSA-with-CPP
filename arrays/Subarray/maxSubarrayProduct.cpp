#include<iostream>
#include<vector>
using namespace std;

int maxSubarrayProduct(vector<int>& nums){
    int maxProduct = nums[0];
    int leftProduct = 1;
    int rightProduct = 1;

    for (int i = 0; i < nums.size(); i++){

        leftProduct = leftProduct == 0 ? 1 : leftProduct;
        rightProduct = rightProduct == 0 ? 1 : rightProduct;

        leftProduct *= nums[i];

        rightProduct *= nums[nums.size()-1-i];

        int currmax = max(leftProduct, rightProduct);

        maxProduct = max(maxProduct, currmax);
    }

        return maxProduct;
}

int main(){
    vector<int> nums = {2, -3, 6, -5, 4, 2};

    cout << "Maximum Subarray Product: " << maxSubarrayProduct(nums) << endl;

    return 0;
}