#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i) {
    if (i == n - 1) return true;    //base case.
    if (arr[i] > arr[i + 1]) return false;  
    return isSorted(arr, n, i + 1); //recursive call.
}

int main() {
    int arr[] = { 1,2,3,4,5 };
    int arr1[] = { 1,2,3,4,5,7,6 };
    int i = 0;
     
    cout << isSorted(arr, 5, i) << endl;
    cout << isSorted(arr1, 7, i) << endl;
    return 0;
}