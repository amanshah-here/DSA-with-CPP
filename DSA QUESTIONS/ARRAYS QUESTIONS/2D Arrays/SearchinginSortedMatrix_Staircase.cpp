#include<iostream>
using namespace std;

int staircaseSearch(int arr[][4],int m,int n,int key){
    int row = 0,col=n-1; //!starting from the top right corner

    while(row < n && col >= 0){
        if(arr[row][col] == key){ //! checking if the corner value is equal to the key
            cout << "Found at index : ( " << row << " , " << col << " )" << endl;
            return 0;
        }
        else if(arr[row][col] > key){ //! if the value is greater than the key then move left
            col--;
        }
        else{   //! if the value is less than the key then move down
            row++;
        }
    }
    return -1; //! if the key isn't found then return -1
}

int main(){
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int m = 4, n = 4;
    int key = 33;

    cout << staircaseSearch(arr, m, n, key);

    return 0;
}