class Solution {
public:
    int solveME(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2, int n, 
                vector<vector<vector<vector<int>>>>& dp) {
        // Base Case: Check for invalid positions
        if (x1 >= n || y1 >= n || x2 >= n || y2 >= n || 
            grid[x1][y1] == -1 || grid[x2][y2] == -1) {
            return INT_MIN;
        }

        // Base Case: Both players reach the end
        if (x1 == n - 1 && y1 == n - 1) {
            return grid[x1][y1];
        }

        // Check if already computed
        if (dp[x1][y1][x2][y2] != -1) {
            return dp[x1][y1][x2][y2];
        }

        // Initial cherries collected at (x1, y1) and (x2, y2)
        int cherries = grid[x1][y1];
        if (x1 != x2 || y1 != y2) {  // Avoid double counting if both are at the same cell
            cherries += grid[x2][y2];
        }

        // Explore all 4 possible moves for both players
        int maxCherries = max({
            solveME(grid, x1 + 1, y1, x2 + 1, y2, n, dp),  // Both move down
            solveME(grid, x1 + 1, y1, x2, y2 + 1, n, dp),  // First moves down, second moves right
            solveME(grid, x1, y1 + 1, x2 + 1, y2, n, dp),  // First moves right, second moves down
            solveME(grid, x1, y1 + 1, x2, y2 + 1, n, dp)   // Both move right
        });

        // Memoize and return the result
        return dp[x1][y1][x2][y2] = cherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // 4D DP: dp[x1][y1][x2][y2]
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        
        return max(0, solveME(grid, 0, 0, 0, 0, n, dp));
    }
};
