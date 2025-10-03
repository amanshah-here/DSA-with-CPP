#include<iostream>
#include<vector>
using namespace std;

int searchInRotated(vector<int>& nums, int st, int end, int target) { //O(logn)
    if (st > end) return -1;    //base case.
    int mid = st + (end - st) / 2;  //calculating mid.
    
    if (nums[mid] == target) return mid;    //target found.

    else if (nums[st] <= nums[mid]) {   //Left sorted, mid lies on line 1.
        if (nums[st] <= target && target <= nums[mid]) {  //Left half.
            searchInRotated(nums, st, mid - 1, target);
        }
        else {  //right half.
            searchInRotated(nums, mid + 1, end, target);
        }
    }
    else {  //right sorted, mid lies on line 2.
        if (nums[mid] <= target && target <= nums[end]) { //right half.
            searchInRotated(nums, mid + 1, end, target);
        }
        else {  //left half.
            searchInRotated(nums, st, mid - 1, target);
        }
    }
}

int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int st = 0, end = nums.size() - 1;
    int target = 2;
    cout << searchInRotated(nums, st, end, target) << endl;
    return 0;
}