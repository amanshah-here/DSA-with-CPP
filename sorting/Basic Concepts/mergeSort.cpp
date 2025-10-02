#include<iostream>
#include<vector>
using namespace std;

//function to combine the divided arrays.
void merge(vector<int>& arr, int st, int end, int mid) {    //O(n)
    vector<int> temp;   //a temporary vector to store the answers.
    int i = st; //start of left array.
    int j = mid + 1;    //start of right array.
    while (i <= mid && j <= end) {
        //pushing the smaller element b/w right and left array in temp.
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
            
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {  //pushing if left array have any remaining element.
        temp.push_back(arr[i++]);
    }

    while (j <= end) {  //pushing if right array have any remaining element.
        temp.push_back(arr[j++]);
    }

    //copying the element from temporary array to original array.
    for (int idx = st, k = 0; idx <= end; idx++) { 
        arr[idx] = temp[k++];
    }
}

void mergeSort(vector<int>& arr, int st, int end) { //O(nlogn)
    if (st >= end) return;

    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);    //left half.
    mergeSort(arr, mid + 1, end);   //right half.
    merge(arr, st, end, mid);   
}

void print(vector<int>& arr) {  //a utility function to print the array.
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 6,3,7,5,2,4 };
    int st = 0;
    int end = arr.size() - 1;
    mergeSort(arr, st, end);
    print(arr);
    return 0;
}