#include<iostream>
#include<vector>
using namespace std;

int Bs(vector<int>& arr,int target,int st,int end){
    if(st<=end){

        int mid = st + (end - st) / 2;

        if(arr[mid] > target){
            return Bs(arr, target, st, mid - 1);
        }else if(arr[mid]<target){
            return Bs(arr, target, mid + 1, end);
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 21};
    int st = 0;
    int end = arr.size()-1;
    int target = 21;
    cout << Bs(arr, target, st, end);
    return 0;
}