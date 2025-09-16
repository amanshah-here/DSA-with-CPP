#include<iostream>
using namespace std;

int searching(int arr[][4],int m,int n,int key){

    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if(arr[i][j] == key){
                
                cout << "Found at index : ( " << i << " , " << j << " )" << endl;
                return 0;
            }
        }
    }
    return -1;
}

int main(){
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int m = 4, n = 4;
    int key = 33;

    cout << searching(arr, n, m, key);

    return 0;
}