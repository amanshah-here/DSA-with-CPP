#include<iostream>
#include<vector>
using namespace std;

//Question: given a sorted vector and a target. we have to find if any pair in the sorted vector has sum = target.

//soln: here we are using two pointers approach.

vector<int> pairSum(vector<int> nums, int target) {
    int st = 0;
    int end = nums.size() - 1;

    vector<int> ans;   //an another vector to store the pair
    
    while (st < end) {
        int sum = nums.at(st) + nums.at(end);   //calculating the sum of 1st and last element.

        if (sum > target) {     //moving to the index before end if sum is greater than target.
            end--;
        }
        else if (sum < target) {    //moving to the index after st if sum is less than target.
            st++;
        }
        else {  //pushing st and end to the ans vector when the answer is found.
            ans.push_back(st);
            ans.push_back(end);
            
            return ans;
        }
    }
    
    return ans;
}

int main() {
    vector<int> vec = { 1,4,6,7,23,44,53 };
    int target = 13;
    vector<int> ans = pairSum(vec, target);

    cout << ans[0] << " , " << ans[1] << endl;

    return 0;
}