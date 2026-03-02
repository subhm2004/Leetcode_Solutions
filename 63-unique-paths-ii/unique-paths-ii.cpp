class Solution {
public:
    int solveRE(int i, int j, vector<vector<int>>& obstacleGrid) {
        // Base cases
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) {
            return 0; // Out of bounds or obstacle
        }
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1; // Reached the destination
        }

        int right_paths = solveRE(i, j + 1, obstacleGrid);
        int down_paths = solveRE(i + 1, j, obstacleGrid);

        return right_paths + down_paths;
    }

    int solveME(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // Base cases
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) {
            return 0; // Out of bounds or obstacle
        }
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1; // Reached the destination
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return precomputed result
        }

        int right_paths = solveME(i, j + 1, obstacleGrid, dp);
        int down_paths = solveME(i + 1, j, obstacleGrid, dp);

        return dp[i][j] = right_paths + down_paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solveME(0, 0, obstacleGrid, dp);
    }
};
