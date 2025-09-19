#include<iostream>
#include<vector>
using namespace std;

int searching(vector<int> &nums){

    int st = 1;
    int end = nums.size() - 2;

    while(st<=end){
        int mid = st + (end - st) / 2;
        if(nums[mid-1] <= nums[mid] && nums[mid] >= nums[mid+1])
            return mid;
        //searching for the peak variable's position(left or right)
        if(nums[mid]>nums[mid-1])
            st = mid + 1;
        else
            end = mid - 1;
        
    }
    return -1;
}
int main(){

    vector<int> nums = {0, 2, 4, 5, 7, 8, 10, 8, 6, 4, 2, 1};
    cout << searching(nums);
    return 0;
}