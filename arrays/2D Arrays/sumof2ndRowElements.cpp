#include<iostream>
using namespace std;

int sum(int arr[][3],int m,int n){
    int total = 0;
    for (int i = 0; i < n;i++){
        total += arr[1][i];
    }

    return total;
}

int main(){
    int arr[3][3] = {{1, 4, 9}, {11, 4, 3}, {2, 2, 3}};
    int n = 3, m = 3;

    cout << "Sum of elements of 2nd row : " << sum(arr, m, n) << endl;

    return 0;
}