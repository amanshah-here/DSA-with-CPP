#include<iostream>
using namespace std;

int count(int arr[][3],int m,int n){
    int c = 0;
    int st = 0,end=n-1;

    for (int i = 0; i < m; i++){    //row
        for (int j = 0; j < n; j++){    //column
            if(arr[i][j] == 7){
                c++;
            }
        }
    }
    return c;
}

int main(){
    int arr[3][3] = {{1, 2, 7}, {7, 3, 4}, {27, 7, 34}};
    int m = 3, n = 3;

    cout << "Total numbers of 7's in the matrix : " << count(arr, m, n) << endl;

    return 0;
}