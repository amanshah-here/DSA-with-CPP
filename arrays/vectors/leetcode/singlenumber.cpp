#include<iostream>
#include<vector>
using namespace std;

int single(vector<int> &vec){
    int ans = 0;
    for(int val:vec){
        ans ^= val;
    }
    return ans;
}

int main()
{
    vector<int>vec={1,2,1,2,4};
    cout << "single number in the array is: " << single(vec) << endl;

    return 0;
}