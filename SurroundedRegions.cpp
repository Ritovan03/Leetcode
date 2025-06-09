class Solution {
public:
    int m, n;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'S';  // Mark as safe

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& [dx, dy] : dir) {
                int di = x + dx, dj = y + dy;
                if (di >= 0 && di < m && dj >= 0 && dj < n && board[di][dj] == 'O') {
                    board[di][dj] = 'S';
                    q.push({di, dj});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();

        // Start BFS from border 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n - 1] == 'O') bfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m - 1][j] == 'O') bfs(board, m - 1, j);
        }

        // Flip remaining 'O's to 'X', and 'S' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};

//MORE INTUITIVE AND MY ORIGINAL SOLUTION

// class Solution {
// public:
//     int m, n;
//     vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         visited[i][j] = true;

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             for (auto& [dx, dy] : dir) {
//                 int nx = x + dx, ny = y + dy;
//                 if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
//                     !visited[nx][ny] && board[nx][ny] == 'O') {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//     }

//     void solve(vector<vector<char>>& board) {
//         if (board.empty()) return;

//         m = board.size();
//         n = board[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));

//         // Traverse border 'O's and do BFS
//         for (int i = 0; i < m; i++) {
//             if (board[i][0] == 'O' && !visited[i][0])
//                 bfs(board, visited, i, 0);
//             if (board[i][n - 1] == 'O' && !visited[i][n - 1])
//                 bfs(board, visited, i, n - 1);
//         }

//         for (int j = 0; j < n; j++) {
//             if (board[0][j] == 'O' && !visited[0][j])
//                 bfs(board, visited, 0, j);
//             if (board[m - 1][j] == 'O' && !visited[m - 1][j])
//                 bfs(board, visited, m - 1, j);
//         }

//         // Flip all unvisited 'O' to 'X'
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == 'O' && !visited[i][j]) {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };
