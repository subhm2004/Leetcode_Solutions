class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front(); // Queue se current cell lo
            q.pop();

            // 4 directions me check karo (up, down, left, right)
            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Agar valid hai aur `1` hai to usko `0` mark karo aur queue me
                // daalo
                if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                    ny < grid[0].size() && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0; // Visited mark kar diya
                    q.push({nx, ny});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Saare boundary ke land cells (`1s`) ko queue me daalo aur unko `0`
        // mark karo
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i * j == 0 || i == m - 1 || j == n - 1) &&
                    grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; // Visited mark kar diya
                }
            }
        }

        // BFS run karke boundary-connected lands hatao
        bfs(grid, q);

        // Bache hue land cells (`1s`) ko count 
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
