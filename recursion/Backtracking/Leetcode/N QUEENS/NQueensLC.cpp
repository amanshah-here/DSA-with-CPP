#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<string>>& ans) {
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << "\n";
        }
    }
    cout << "\n";
}
bool isSafe(vector<string>& board, int row, int  col) {
    int n = board.size();

    //Horizontal Safety Check
    // for (int j = 0; j < n; j++) {
    //     if (board[row][j] == 'Q') {
    //         return false;
    //     }
    // }

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

void nQueens(vector<string>& board, int row, vector<vector<string>>& ans) {
    int n = board.size();
    if (row == n) { //base case
        ans.push_back(board);   //pushing every soln to ans.
        return;
    }

    for (int j = 0; j < n; j++) {   // looping on the columns to traverse each column.
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';    //placing Queen
            nQueens(board, row + 1, ans);    //recursive call for next row.
            board[row][j] = '.';    //backtrack
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(board, 0, ans);
    print(ans);
    return 0;
}