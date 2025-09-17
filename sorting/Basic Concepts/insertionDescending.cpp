#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&arr,int n){        //O(n^2)

    for (int i = 1; i < n ;i++){
        int current = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] < current){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;    //placing the current element in its correct position
    }
}

void printarr(vector<int> &arr, int n){

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2, 4, 3, 5, 1};
    int n = arr.size();

    insertionSort(arr, n);
    printarr(arr, n);

    return 0;
}