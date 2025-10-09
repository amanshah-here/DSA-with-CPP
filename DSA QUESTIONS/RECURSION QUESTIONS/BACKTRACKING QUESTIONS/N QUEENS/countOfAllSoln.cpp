#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<char>>& board) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------\n";
}

bool isSafe(vector<vector<char>>& board, int row, int  col) {
    int n = board.size();

    //Horizontal Safety Check
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    //Vertical Safety Check
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    //Diagonal Left Safety Check
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    //Digonal Right Safety Check
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

int nQueens(vector<vector<char>>& board, int row) {
    int n = board.size();

    if (row == n) { //base case
        printBoard(board);
        return 1;
    }
    int count = 0;
    for (int j = 0; j < n; j++) {   // looping on the columns to traverse each column.
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';    //placing Queen
            count += nQueens(board, row + 1);    //recursive call for next row.
            board[row][j] = '.';    //backtrack
        }
    }
    return count;   //total number of possible solutions at ech level.
}
int main() {
    vector<vector<char>> board;
    int n = 4;
    for (int i = 0; i < n; i++) {
        vector<char> newRow;
        for (int j = 0; j < n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count = nQueens(board, 0);
    cout << "Total number of solutions: " << count << endl;
    return 0;
}