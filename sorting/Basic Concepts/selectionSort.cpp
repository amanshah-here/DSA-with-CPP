#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int>&arr,int n){        //O(n^2)

    for (int i = 0; i < n - 1;i++){
        
        int smallIndx = i;  //unsorted part's starting
        for (int j = i + 1; j < n;j++){

            if(arr[j] < arr[smallIndx]){
                smallIndx = j;
            }
        }
        swap(arr[i], arr[smallIndx]);
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

    SelectionSort(arr, n);
    printarr(arr, n);

    return 0;
}