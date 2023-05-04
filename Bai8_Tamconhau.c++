#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<int>& board) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row] == col) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check for conflicts with previous rows
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row) {
    if (row == 8) {
        printBoard(board);
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solve(board, row + 1);
            board[row] = -1;
        }
    }
}

int main() {
    vector<int> board(8, -1);
    solve(board, 0);
    return 0;
}
