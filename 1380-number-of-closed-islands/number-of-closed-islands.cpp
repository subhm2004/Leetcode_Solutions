#include <queue>
#include <vector>

class Solution {
public:
    // Helper function for BFS
    void bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        // Directions vector for 4 possible movements (up, down, left, right)
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1; // Mark as visited
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Explore all 4 directions
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    grid[newX][newY] = 1; // Mark as visited
                    q.push({newX, newY});
                }
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Remove the lands connected to the edge
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i * j == 0 || i == m - 1 || j == n - 1) {
                    if (grid[i][j] == 0) {
                        bfs(grid, i, j); // Perform BFS from the edge
                    }
                }
            }
        }

        int ans = 0;
        // Count closed islands
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j); // Perform BFS to mark the closed island
                    ++ans;
                }
            }
        }

        return ans;
    }
};
