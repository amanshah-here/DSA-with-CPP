#include<iostream>
using namespace std;

int diagonalSum(int arr[3][3],int n){

    int primaryDiagonalSum = 0;
    int secondryDiagonalSum = 0;
    int totalSum = 0;

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(i == j){
                primaryDiagonalSum += arr[i][j];
            }
            else if(j==n-i-1){
                secondryDiagonalSum += arr[i][j];
            }
        }
    }
    totalSum = primaryDiagonalSum + secondryDiagonalSum;
    return totalSum;
}

int main(){
    int arr[4][4] = {{1, 2, 3,4}, { 5, 6,7,8}, { 9,10,11,12},{13,14,15,16}};
    int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // int n = 4;

    // cout<<"Sum of both primary and secondry diagonal elements :"<<diagonalSum(arr, n)<<endl;

    int n = 3;
    cout<<"Sum of both primary and secondry diagonal elements :"<<diagonalSum(arr2, n)<<endl;

    return 0;
}