#include<iostream>
#include<vector>
using namespace std;

//Function that divides the array into two part based on the pivot.
int partition(vector<int>& arr, int st, int end) {
    int i = st - 1; //an iterator pointing before the starting index of array.
    int pivot = arr.at(end);    //taking last element as pivot.

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {  //if an element is smaller than pivot then push it to left.
            swap(arr.at(++i), arr.at(j));
        }
    }
    swap(arr.at(++i), arr.at(end)); //pushing pivot to its best position.
    return i;   //returning the index on which the pivot is.
}

void quickSort(vector<int>& arr, int st, int end) { //avg: O(nlogn)  || worst case: O(n^2)
    if (st >= end) return;
    int pivotIdx = partition(arr, st, end); // divides the array into two parts and gives the index of pivot.
    //recursive call for left half.
    quickSort(arr, st, pivotIdx - 1);
    //recursive call for right half.
    quickSort(arr, pivotIdx + 1, end);
}

void print(vector<int>& arr) {  //an utility function to print the array.
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 6,3,7,5,2,4 };
    int st = 0, end = arr.size() - 1;
    quickSort(arr, st, end);
    print(arr);
    return 0;
}