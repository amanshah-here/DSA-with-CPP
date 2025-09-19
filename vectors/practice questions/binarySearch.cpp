#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int st = 0;
    int end = nums.size() - 1;

    while(st<=end){
        int mid = (st + end) / 2;
        
        if(target>nums[mid])
            st = mid + 1;
        else if(target < nums[mid])
            end = mid - 1;
        else{
            cout << "found at index ";
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> nums = {-1, 2, 4, 5, 7, 9, 13, 21};
    int target = 21;
    cout << binarySearch(nums, target);
    return 0;
}
