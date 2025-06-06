class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        // Check upper column
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][col] == 'Q') return false;
        }
        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(result, board, row + 1, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        solve(result, board, 0, n);
        return result;
    }
};
