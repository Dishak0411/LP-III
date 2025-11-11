#include <bits/stdc++.h>
using namespace std;

int n, fixedR, fixedC;

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Same column (check all rows)
    for (int i = 0; i < n; i++)
        if (board[i][col] == 1) return false;

    // \ diagonal (up-left & down-right)
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1) return false;
    for (int i = row+1, j = col+1; i < n && j < n; ++i, ++j)
        if (board[i][j] == 1) return false;

    // / diagonal (up-right & down-left)
    for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 1) return false;
    for (int i = row+1, j = col-1; i < n && j >= 0; ++i, --j)
        if (board[i][j] == 1) return false;

    return true;
}

bool solve(vector<vector<int>>& board, int row) {
    if (row == n) return true;

    // Skip the fixed row; it already has the queen
    if (row == fixedR) return solve(board, row + 1);

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solve(board, row + 1)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter size of chessboard (N): ";
    cin >> n;
    cout << "Enter the row (0-based) where the first queen is placed: ";
    cin >> fixedR;
    cout << "Enter the column (0-based) where the first queen is placed: ";
    cin >> fixedC;

    if (fixedR < 0 || fixedR >= n || fixedC < 0 || fixedC >= n) {
        cout << "Invalid fixed position.\n";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));
    board[fixedR][fixedC] = 1;

    if (solve(board, 0)) {
        cout << "\nFinal N-Queens Solution:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "\nNo valid solution exists after placing the first queen there.\n";
    }
    return 0;
}