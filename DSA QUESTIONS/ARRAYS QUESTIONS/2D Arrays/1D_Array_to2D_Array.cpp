#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool is_prime(int num){
    
    if(num <= 1){
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void print(vector<vector<int>> &arr,int m ,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> to2D(vector<int> &arr,int m,int n){
    vector<vector<int>> matrix;
    int size = arr.size();

    if(size == 0 || is_prime(size)){
        return matrix;
    }
    matrix.resize(m, vector<int>(n));
        
        
    int idx = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = arr[idx];
            idx++;
        }
    }
   
    print(matrix, m, n);
    return matrix;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8,9};
    int m = 3, n = 3;

    vector<vector<int>> result = to2D(arr, m, n);

    if (result.empty()) {
        cout << "Matrix was not created." << endl;
    }

    return 0;
}
