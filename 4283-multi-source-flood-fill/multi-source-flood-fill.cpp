class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void multi_source_bfs(vector<vector<int>>& grid, vector<vector<int>>& dist,
                          int n, int m) {
        queue<pair<int, int>> q;

        // sare source ko queue me daal do
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

            for (auto& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                // boundary conditions
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // first time aya hai cell pr
                if (dist[nr][nc] == 0x3f3f3f3f) {
                    dist[nr][nc] = dist[r][c] + 1;
                    grid[nr][nc] = grid[r][c];

                    q.push({nr, nc});
                }

                // same time pr aa gya
                else if (dist[nr][nc] == dist[r][c] + 1) {
                    grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                }
            }
        }
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (auto& src : sources) {
            int r = src[0], c = src[1], color = src[2];

            grid[r][c] = color;
        }
        vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));

        multi_source_bfs(grid, dist, n, m);

        return grid;
    }
};