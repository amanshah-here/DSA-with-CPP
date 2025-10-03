#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int st, int end, int mid) {
    vector<int> sortedArr;
    int i = st;
    int j = mid + 1;
    int count = 0;
    // left -> [start .... mid] ==> start = start, end = mid;
   // right -> [mid+1 .... end] ==> start = mid+1, end = end;
    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
                //left element > right element
                // we have inversions
                // # of inversions = (lastIndex of left array - currentIndex of left array + 1)
                // lastIndex of left = mid
                // currentIndex of left = i
                // # of inversions = (mid - i + 1)
            count += (mid - i + 1);
            sortedArr.push_back(arr.at(j++));
        }
        else {
            sortedArr.push_back(arr.at(i++));
        }
    }
    // if elements in the left array still remain
    while (i <= mid) {
        sortedArr.push_back(arr.at(i++));
    }
    // if elements in the right array still remain
    while (j <= end) {
        sortedArr.push_back(arr.at(j++));
    }
    //copying the element of sortedArr into original array.
    for (int i = st, x = 0; i <= end; i++) {
        arr[i] = sortedArr[x++];
    }
    return count;
}

int countInversion(vector<int>& arr, int st, int end) {
    if (st >= end) return 0;
    int mid = st + (end - st) / 2;

    int leftInversion = countInversion(arr, st, mid);   //recursive call for leftpart.
    int rightInversion = countInversion(arr, mid + 1, end); //recursive call for right part.
    int crossInversion = merge(arr, st, end, mid);  //inversion count b/w both left and right part.
    return leftInversion + rightInversion + crossInversion; // returning the total inversion count.
}

int main() {
    vector<int> arr = { 2,4,1,5,3 };
    int st = 0, end = arr.size() - 1;
    cout << countInversion(arr, st, end);
    return 0;
}