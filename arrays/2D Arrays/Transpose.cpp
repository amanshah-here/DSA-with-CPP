#include<iostream>
using namespace std;

void print(int matrix[2][3],int row,int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void transpose(int matrix[2][3],int row,int col){
    int transpose[col][row] = {{0}};

    cout << "Original Matrix: \n";
    print(matrix, row, col);
    cout << endl;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){

            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose : \n";
    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int row = 2, col = 3;

    transpose(matrix, row, col);

    return 0;
}


