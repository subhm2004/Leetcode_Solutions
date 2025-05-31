class Solution {
public:
    pair<int, int> getCoord(int s, int n) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;

        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0))
            col = n - 1 - col;

        return {row, col};
    }

    int bfs(vector<vector<int>>& board, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);
        visited[n - 1][0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front();
                q.pop();

                if (x == n * n)
                    return steps;

                for (int k = 1; k <= 6 && x + k <= n * n; ++k) {
                    auto [r, c] = getCoord(x + k, n);
                    if (visited[r][c])
                        continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1)
                        q.push(x + k);
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }

        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        return bfs(board, n);
    }
};
