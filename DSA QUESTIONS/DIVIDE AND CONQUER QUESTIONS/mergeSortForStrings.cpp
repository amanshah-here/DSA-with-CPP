#include<iostream>
#include<vector>
#include<string>
using namespace std;

void merge(vector<string>& arr, int st, int end, int mid) {
    int i = st;
    int j = mid + 1;
    vector<string> temp;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= end) {
        temp.push_back(arr[j++]);
    }
    for (int idx = st, x = 0; idx <= end; idx++) {
        arr[idx] = temp[x++];
    }
}

void mergeSort(vector<string>& arr, int st, int end) {
    if (st >= end) return;
    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, end, mid);
}

void print(vector<string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<string> arr = { "sun","earth","mars","mercury" };
    int st = 0, end = arr.size() - 1;
    mergeSort(arr, st, end);
    print(arr);
    return 0;
}