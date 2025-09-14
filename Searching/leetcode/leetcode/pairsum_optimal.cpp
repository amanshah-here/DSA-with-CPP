#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> vec,int target){

    int i = 0;
    int n = vec.size();
    int j = (n - 1);
    vector<int> ans;

    while(i<j){
        int ps = vec[i] + vec[j];
        if(ps>target){
            j--;
        }
        else if(ps<target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
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