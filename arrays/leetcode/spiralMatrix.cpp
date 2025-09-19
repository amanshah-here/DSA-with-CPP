#include<iostream>
#include<vector>
using namespace std;


void print(vector <int>& arr){
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> spiral(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();

    int srow = 0, scol = 0;
    int erow = m - 1, ecol = n - 1;

    vector<int> spirals;

    while(srow <= erow && scol <= ecol){

        //! traversing top row's elements
        for (int i = scol; i <= ecol; i++){
            spirals.push_back(arr[srow][i]);
        }

        //! traversing right column's elements
        for (int j = srow + 1; j <= erow; j++){
            spirals.push_back(arr[j][ecol]);
        }

        //! traversing bottom row's elements
        for (int i = ecol - 1; i >= scol; i--){

            //? corner case for matrix with odd numbers of rows
            if(srow == erow){
                break;
            }
            spirals.push_back(arr[erow][i]);
        }

        //! traversing left column's elements
        for (int j = erow - 1; j >= srow + 1; j++){
            //? corner case for matrix with odd number of rows
            if(scol == ecol){
                break;
            }
            spirals.push_back(arr[j][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    print(spirals);

    return spirals;
}



int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    spiral(arr);

    return 0;
}
