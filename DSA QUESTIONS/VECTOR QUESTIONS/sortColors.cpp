#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0;    //position of 0's
    int mid = 0;    //position of 1's
    int high = nums.size() - 1; //position of 2's

    while (mid <= high) {
        if (nums.at(mid) == 0) swap(nums.at(low++), nums.at(mid++));
        else if (nums.at(mid) == 1) mid++;
        else swap(nums.at(mid), nums.at(high--));
    }
}

int main() {
    vector<int> nums = { 2,0,2,1,1,0 };
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << " ";
    }
    return 0;
}