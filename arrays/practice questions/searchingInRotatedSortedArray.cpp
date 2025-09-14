#include<iostream>
#include<vector>
using namespace std;

int searching(vector<int>& nums,int target){
    int st = 0;
    int end = nums.size() - 1;

    while(st<=end){
        int mid = st + (end - st) / 2;

        if(nums[mid] == target){
            return mid;
        }

        //now checking for the sorted part
        else if(nums[st] <= nums[mid]){
            //if this codition is true that means the left part of the array is sorted
            if (nums[st] <= target && target <= nums[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        else{
            //if the right part of the array is sorted
            if(nums[mid] <= target && target <= nums[end]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return - 1;
}

int main(){
    vector<int> nums = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 1;

    cout << "index: " << searching(nums, target);

    return 0;
}