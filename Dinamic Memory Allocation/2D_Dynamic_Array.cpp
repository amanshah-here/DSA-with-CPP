#include<iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    int** matrix = new int* [rows];

    for (int i = 0;i < rows;i++) {
        matrix[i] = new int[cols];
        for (int j = 0;j < cols;j++) {
            cout << "Enter Value at [ " << i << " ][ " << j << " ] Index: ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}