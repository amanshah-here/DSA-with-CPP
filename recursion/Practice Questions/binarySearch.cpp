#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> nums, int target, int st, int end) {
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            return binarySearch(nums, target, st, mid - 1);
        }
        else {
            return binarySearch(nums, target, mid + 1, end);
        }
    }
    return -1;
}

int main() {
    vector<int> nums = { 1,2,4,5,6,7,8,9,11,13 };
    int target = 11;
    int st = 0, end = nums.size() - 1;
    cout << binarySearch(nums, target, st, end) << endl;
    return 0;
}