#include<iostream>
#include<vector>
using namespace std;

/* Question: Find the xorBeauty of an array 'nums'.
    • Given a 0-Indexed array.
    • The Effective value of three indices i, j, k is defined as  ((nums[i] | nums[j]) & nums[k])
    • The XorBeauty of an array is the XORing of the Effective value of all the possible triplets of indices (i, j, k) where (0 <= i, j, k < n)
*/

//* Soln: In An array the effective value of the three indices when i != j or j != k or i != k Always appears twice but the effective values of same indices i.e. i = j = k apperars once, that means we just need to find the xor of the individual elements of the array bcz the xor of same values is 0. 

int xorBeauty(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        ans ^= x;
    }
    return ans;
}

int main() {
    vector<int> nums = { 15,45,20,2,34,35,5,44,32,30 };
    cout << "XOR Beauty of array: " << xorBeauty(nums) << endl;

    return 0;
}