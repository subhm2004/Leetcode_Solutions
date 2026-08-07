class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void multi_source_BFS(vector<vector<int>>& grid, vector<vector<int>>& dist,
                        int n, int m) {

        queue<pair<int, int>> q;

        // Sabhi colored cells ko source banao
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // First time reach
                if (dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    grid[nr][nc] = grid[r][c];

                    q.push({nr, nc});
                }

                // Same time arrival
                else if (dist[nr][nc] == dist[r][c] + 1) {

                    grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                }
            }
        }
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        for (auto& src : sources) {

            int r = src[0];
            int c = src[1];
            int color = src[2];

            grid[r][c] = color;
        }

        multi_source_BFS(grid, dist, n, m);

        return grid;
    }
};