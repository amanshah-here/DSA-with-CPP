#include<iostream>
#include<vector>
using namespace std;

void findOccurrance(vector<int>& nums, int key, int idx) {
    if (idx > nums.size() - 1) return;   
    if (nums.at(idx) == key) {
        cout << idx << " ";
    }
    findOccurrance(nums, key, idx + 1);
}

int main() {
    vector<int> nums = { 1,3,4,5,2,3,4,6,3,3 };
    int key = 3;
    int idx = 0;
    findOccurrance(nums, key, idx);
    return 0;
}