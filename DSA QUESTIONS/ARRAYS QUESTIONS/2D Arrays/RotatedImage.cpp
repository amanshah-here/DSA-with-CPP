#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<vector<int>> &arr,int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int rotatedImage(vector<vector<int>> &matrix){
    int m, n;
    m = n = matrix.size();

    cout << "matrix before: "<<endl;
    print(matrix, m, n);

    //transpose
    for (int i = 0; i < m; i++){
        for (int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //reverse
    for (int i = 0; i < n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

        cout << "\n matrix after: " << endl;
    print(matrix, m, n);
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotatedImage(matrix);
}