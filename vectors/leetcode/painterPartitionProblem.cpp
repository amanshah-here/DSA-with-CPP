#include<iostream>
#include<vector>
using namespace std;

bool isValied(vector<int>&arr,int painters,int boards,int maxTime){
    int pNo = 1;
    int time = 0;

    for (int i = 0; i < boards;i++){        //O(n)

        //edge case
        if(arr[i]>maxTime)
            return false;

        if(time+arr[i]<=maxTime){
            time += arr[i];
        }else{
            pNo++;
            time = arr[i];
        }
    }

    if(pNo>painters)
        return false;
    else
        return true;
}
int partition(vector<int>&arr,int painters,int boards){     //O(logN * n)

    if (painters > boards)
        return -1;

    int sum = 0;
    int max_val = INT8_MIN;

    for (int i = 0; i < boards;i++){        //O(n)
        sum += arr[i];
        max_val = max(max_val, arr[i]);
    }

    int st = max_val, end = sum;//range of possible answers
    int ans = -1;

    while (st <= end)       //O(logN)
    {
        int mid = st + (end - st) / 2;
        if (isValied(arr,painters,boards,mid)){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return ans;
}

int main(){

    vector<int> arr = {40, 30, 10, 20};
    int painters = 2;
    int boards = arr.size();

    cout << partition(arr, painters, boards);
    return 0;
}