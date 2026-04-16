class Solution {
public:
int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        const int m = grid.size();
        const int n = grid[0].size();
        int connected_count = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        // Directions for row and column traversal
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            connected_count++;

            // Check row
            for (int ny = 0; ny < n; ++ny) {
                if (ny != y && grid[x][ny] == 1 && !visited[x][ny]) {
                    visited[x][ny] = true;
                    q.push({x, ny});
                }
            }

            // Check column
            for (int nx = 0; nx < m; ++nx) {
                if (nx != x && grid[nx][y] == 1 && !visited[nx][y]) {
                    visited[nx][y] = true;
                    q.push({nx, y});
                }
            }
        }

        return connected_count;
    }
    int countServers(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);

        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Iterate over the grid and start BFS from each unvisited server
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int connected_count = bfs(i, j, grid, visited);
                    // If this group of connected servers has more than 1 server, add them to the answer
                    if (connected_count > 1) {
                        ans += connected_count;
                    }
                }
            }
        }

        return ans;
    }
};
