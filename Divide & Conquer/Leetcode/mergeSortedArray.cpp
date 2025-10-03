#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
    int i = 0;
    int j = 0;
    vector<int> temp;
    while (i <= m - 1 && j <= n - 1) {
        if (num1[i] >= num2[j]) {
            temp.push_back(num2[j++]);
        }
        else {
            temp.push_back(num1[i++]);
        }
    }
    while (i <= m - 1) {
        temp.push_back(num1[i++]);
    }
    while (j <= n - 1) {
        temp.push_back(num2[j++]);
    }
    for (int idx = 0; idx <= m + n - 1; idx++) {
        num1[idx] = temp[idx];
    }
}

void print(vector<int>& num1) {
    for (int i = 0; i < num1.size(); i++) {
        cout << num1[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> num1 = { 1,2,3,4,0,0,0,0 };
    vector<int> num2 = { 2,3,5,6 };
    int m = 4;
    int n = 4;
    merge(num1, m, num2, n);
    print(num1);
    return 0;
}