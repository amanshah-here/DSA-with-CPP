#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr,int cows,int stalls,int minDistance){

    int C = 1;
    int lastStall = arr[0];

    for (int i = 1; i < stalls;i++){        //O(n)

        if (arr[i] - lastStall >= minDistance)
        {
            C++;
            lastStall = arr[i];
        }

        if(C == cows){
            return true;
        } 
    }

        return false;

}
int cow(vector<int>&arr,int cows,int stalls){

    sort(arr.begin(), arr.end());       //O(Nlogn)
    if(cows>stalls)
        return -1;

    int ans = -1;
    int st = 1, end = arr[arr.size()-1] - arr[0];

    while(st<=end){                 //O(logN * n)
        int mid = st + (end - st) / 2;

        if(isPossible(arr,cows,stalls,mid)){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 8, 4, 9};
    int cows = 3;
    int stalls = arr.size();

    cout << cow(arr, cows, stalls);
    return 0;
}

