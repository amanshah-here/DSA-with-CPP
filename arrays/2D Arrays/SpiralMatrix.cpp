#include<iostream>
using namespace std;

int spiral(int (&arr)[5][5],int n,int m){

    int srow = 0;
    int scol = 0;
    int erow = n - 1;
    int ecol = m - 1;
    
    while(srow <= erow && scol <= ecol){
        //! printing top rows element
        for (int i = scol; i <= ecol;i++){
            cout << arr[srow][i]<<" ";
        }

        //! printing right column elements
        for (int j = srow + 1; j <= erow;j++){
            cout << arr[j][ecol]<<" ";
        }

        //! printing bottom rows element
        for (int i = ecol - 1; i >= scol;i--){
            
            //? corner case for matrix with odd number of rows
            if(srow == erow){
                break;
            }
            cout << arr[erow][i] << " ";
        }

        //! printing left column element
        for (int j = erow - 1; j >= srow + 1;j--){

            //? cornercase for matrix with odd number of columns
            if(scol == ecol){
                break;
            }
            cout << arr[j][scol] << " ";
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return 0;
}

int main(){
    int arr[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int n = 5, m = 5;
    spiral(arr,n,m);
}