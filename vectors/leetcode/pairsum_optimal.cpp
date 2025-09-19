#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> vec,int target){

    int st = 0;
    int n = vec.size();
    int end = (n - 1);
    vector<int> ans;

    while(st < end){
        int currSum = vec[st] + vec[end];
        if(currSum > target){
            end--;
        }
        else if(currSum < target){
            st++;
        }
        else{
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {2,7,11,15};
    int target = 26;

    vector<int> ans = pairsum(vec, target);
    cout << ans[0] << "," << ans[1] << endl;
    return 0;
}