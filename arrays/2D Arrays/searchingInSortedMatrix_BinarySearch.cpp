#include<iostream>
using namespace std;

int searching(int arr[][4],int m,int n,int key){

    for (int i = 0; i < m;i++){
        int st = 0, end = n - 1;
        while(st <= end){

            int mid = st + (end - st) / 2;

            if(arr[i][mid] == key){
                cout << "Found at index : ( " << i << " , " << mid << " )" << endl;

                return 0;
            }
            else if(arr[i][mid] > key){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
    }
    return -1;
}
    


int main(){
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int m = 4, n = 4;
    int key = 33;

    cout << searching(arr, m, n, key);

    return 0;
}