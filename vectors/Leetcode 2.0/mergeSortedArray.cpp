#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& num1, int m, vector<int> num2, int n) {
    int num1End = m - 1;
    int num2End = n - 1;
    int mergeEnd = m + n - 1;

    for (int i = mergeEnd; i > num1End; i--) {
        num1[i] = num2[num2End];
        num2End--;
    }
    sort(num1.begin(), num1.end());
}

int main() {
    vector<int>num1 = { 1,2,3,0,0,0 };
    int m = 3;
    vector<int>num2 = { 2,5,6 };
    int n = 3;
     merge(num1, m, num2, n);

    for (int i = 0; i < num1.size(); i++) {
        cout << num1[i] << " ";
    }
    return  0;
}