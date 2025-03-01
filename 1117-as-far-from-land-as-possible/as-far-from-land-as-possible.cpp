class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 directions: right, down, left, up

        // Sare land (1) wale cells ko queue me daal do
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int ans = 0; // Maximum distance store karne ke liye
        int distance = 0; // Current level ka distance

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                ans = distance; // Last valid distance store karega

                // 4 directions me check karo
                for (auto& [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    // Agar boundary ke bahar hai ya already visited (land ya processed water) hai to skip karo
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] > 0) {
                        continue;
                    }
                    q.push({nx, ny});
                    grid[nx][ny] = 2; // Mark as visited taaki dobara process na ho
                }
            }
            ++distance; // Next level ke liye distance badhao
        }

        return ans;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int water = 0;

        // Pura grid traverse karke count karo kitne water cells (0) hai
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++water;
                }
            }
        }

        // Agar grid me sirf land hai ya sirf water hai to -1 return karo
        if (water == 0 || water == m * n) {
            return -1;
        }

        return bfs(grid); // BFS call karke max distance return karo
    }
};
