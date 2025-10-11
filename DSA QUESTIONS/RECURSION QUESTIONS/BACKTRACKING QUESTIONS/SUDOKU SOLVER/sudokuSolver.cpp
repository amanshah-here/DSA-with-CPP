#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>>& sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<int>>& sudoku, int row, int col, int digit) {

    //? Vertical safety check
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) {
            return false;
        }
    }

    //? Horizontal safety check
    for (int j = 0; j < 9; j++) {
        if (sudoku[row][j] == digit) {
            return false;
        }
    }

    //? 3x3 Grid safety check

    int startRow = (row / 3) * 3;   //calculating the starting row of the current 3x3 grid.
    int startCol = (col / 3) * 3;   //calculating the starting column of current 3x3 grid

    for (int i = startRow; i <= startRow + 2; i++) {
        for (int j = startCol; j <= startCol + 2; j++) {
            if (sudoku[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(vector<vector<int>>& sudoku, int row, int col) {

    if (row == 9) {     //! Base case
        print(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;  //updating column every time.
    if (col + 1 == 9) {     //if at last column then go to the next row at first column
        nextRow = row + 1;
        nextCol = 0;
    }
    if (sudoku[row][col] != 0) {    //if the cell already have some values then call for the next cell
        return sudokuSolver(sudoku, nextRow, nextCol);  // will return true if soln exits otherwise false.
    }

    for (int digit = 1; digit <= 9; digit++) {  //looping to check for each digit if previous digit isn't safe.
        if (isSafe(sudoku, row, col, digit)) {  // if the digit is safe to place i.e. if there is no same digit vertically, horizontally, in the current 3x3 Grid.
            sudoku[row][col] = digit;   // then place the digit.
            if (sudokuSolver(sudoku, nextRow, nextCol)) {   // if right element is placed at right cell then will return true, basically if the code is solving correctly.
                return true;
            }
            sudoku[row][col] = 0;   //todo: BACKTRACKING •if the code get to know that any digit placed before is wrong.
        }
    }
    return false;   //if soln doesn't exists or any digit placed before is wrong then return false. 
}
int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9} };
    sudokuSolver(sudoku, 0, 0);
    return 0;
}