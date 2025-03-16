class Solution {
public:
    int solveRE(const vector<vector<int>>& grid, int x, int y1, int y2) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: out of bounds
        if (y1 < 0 || y1 >= n || y2 < 0 || y2 >= n)
            return 0;

        // Base case: last row
        if (x == m - 1) {
            if (y1 == y2)
                return grid[x][y1];
            return grid[x][y1] + grid[x][y2];
        }

        // Calculate current row cherries
        int currRow = grid[x][y1] + (y1 == y2 ? 0 : grid[x][y2]);

        // Define possible moves
        vector<pair<int, int>> moves = {
            {-1, -1}, {-1, 0}, {-1, 1}, // 9 combinations hai moves ke
            {0, -1},  {0, 0},  {0, 1},  {1, -1}, {1, 0}, {1, 1}
        };

        // Recursively find the max cherries for each move
        int maxCherries = INT_MIN;
        for (auto& move : moves) {
            int d1 = move.first;
            int d2 = move.second;
            maxCherries = max(maxCherries, currRow + solveRE(grid, x + 1, y1 + d1, y2 + d2));
        }

        return maxCherries;
    }

    int solveME(const vector<vector<int>>& grid, int x, int y1, int y2, vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (y1 < 0 || y1 >= n || y2 < 0 || y2 >= n)
            return 0;

        if (x == m - 1) {
            if (y1 == y2)
                return grid[x][y1];
            return grid[x][y1] + grid[x][y2];
        }

        if (dp[x][y1][y2] != -1)
            return dp[x][y1][y2];

        int currRow = grid[x][y1] + (y1 == y2 ? 0 : grid[x][y2]);

        vector<pair<int, int>> moves = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},  {0, 0},  {0, 1},  {1, -1}, {1, 0}, {1, 1}
        };

        int maxCherries = INT_MIN;
        for (auto& move : moves) {
            int d1 = move.first;
            int d2 = move.second;
            maxCherries = max(maxCherries, currRow + solveME(grid, x + 1, y1 + d1, y2 + d2, dp));
        }

        dp[x][y1][y2] = maxCherries;
        return dp[x][y1][y2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return solveME(grid, 0, 0, n - 1, dp);
    }
};
