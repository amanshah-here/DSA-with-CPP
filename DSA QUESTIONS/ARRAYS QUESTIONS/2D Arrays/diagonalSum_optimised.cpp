#include<iostream>
using namespace std;

int diagonalSum(int arr[][4],int n){
    int sum = 0;

    // O(n)
    for (int i = 0; i < n;i++){

        sum += arr[i][i]; //adds the value to the sum where i == j basically for the primary diagonal

        if(i != n-i-1){ //checks the corner case to avoid middle element duplicating in odd sized arrays

            sum += arr[i][n - i - 1]; // adds the value to the sum where j == n-i-1 basically for the secondry diagonal
        }
    }
    return sum;
}

int main(){
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = 4;

     cout<<"Sum of both primary and secondry diagonal elements :"<<diagonalSum(arr, n)<<endl;
}