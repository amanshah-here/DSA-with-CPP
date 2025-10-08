// #include<iostream>
// #include<vector>
// using namespace std;

// bool isSafe(vector<string>& board, int row, int  col) {
//     int n = board.size();

//     //Horizontal Safety Check
//     for (int i = 0; i < n; i++) {
//         if (board[row][i] == "Q") {
//             return false;
//         }
//     }

//     //Vertical Safety Check
//     for (int i = 0; i < row; i++) {
//         if (board[i][col] == "Q") {
//             return false;
//         }
//     }

//     //Diagonal Left Safety Check
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//         if (board[i][j] == "Q") {
//             return false;
//         }
//     }

//     //Digonal Right Safety Check
//     for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
//         if (board[i][j] == "Q") {
//             return false;
//         }
//     }

//     return true;
// }

// vector<vector<string>> nQueens(vector<string>& board, int row, vector<vector<string>>& ans) {
//     int n = board.size();
//     if (row == n) { //base case
//         ans.push_back(board);
//         return ans;
//     }

//     for (int j = 0; j < n; j++) {   // looping on the columns to traverse each column.
//         if (isSafe(board, row, j)) {
//             board[row][j] = 'Q';    //placing Queen
//             nQueens(board, row + 1, ans);    //recursive call for next row.
//             board[row][j] = '.';    //backtrack
//         }
//     }
//     return ans;
// }


// vector<vector<string>> calling(int n) {
//     vector<string> board(n, string(n, "."));
//     vector<vector<string>> ans;
//     nQueens(board, 0, ans);
//     return ans;
// }

// int main() {
//     int n = 4;
//     vector<vector<string>> ans = calling(n);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << ans[i][j] << "\n";
//         }
//         cout << endl;
//     }
//     return 0;
// }