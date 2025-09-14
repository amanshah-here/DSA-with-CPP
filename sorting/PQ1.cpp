#include<iostream>
#include<vector>
using namespace std;

int printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        cout << char(arr[i]) << " ";
    }
    cout << endl;
}

int insertionSort(vector<int>& arr){
    for (int i = 1; i < arr.size(); i++){
        int current = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > current){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
    printArray(arr);
}

int main(){
    vector<int> arr = {'f','b','a','e','c','d'};

    insertionSort(arr);

    return 0;
}