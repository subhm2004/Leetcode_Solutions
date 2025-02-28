class Solution {
public:
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                         {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int getMinesCount(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        for (auto& [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
                board[x][y] == 'M') {
                ++count;
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'B'; // Mark as visited

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int minesCount = getMinesCount(board, x, y);
            if (minesCount > 0) {
                board[x][y] = '0' + minesCount;
                continue; // Stop further expansion
            }

            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < board.size() && ny >= 0 &&
                    ny < board[0].size() && board[nx][ny] == 'E') {
                    board[nx][ny] = 'B';
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }

        bfs(board, i, j);
        return board;
    }
};
