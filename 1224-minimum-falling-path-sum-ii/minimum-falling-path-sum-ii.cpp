class Solution {
public:
    int solveRE(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        
        // Base Case: Agar last row tak pahunch gaye, to waha ka value return karo
        if (i == n - 1) return grid[i][j];

        int minNext = INT_MAX;

        // Agli row ke sabhi columns check karo par wahi column repeat mat karo
        for (int next_j = 0; next_j < n; ++next_j) {
            if (next_j == j) continue; // Wahi column skip kar do
            minNext = min(minNext, solveRE(grid, i + 1, next_j));
        }

        // Current cell ka value + next row ka minimum path sum return karo
        return grid[i][j] + minNext;
    }

    int solveME(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int n = grid.size();
        if (i == n - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int minNext = INT_MAX;
        for (int next_j = 0; next_j < n; ++next_j) {
            if (next_j == j) continue;
            minNext = min(minNext, solveME(grid, i + 1, next_j, dp));
        }
        return dp[i][j] = grid[i][j] + minNext;
    }

    int bottomUpDP(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // DP array same as grid (modifying in-place)
        vector<vector<int>> dp = grid;

        // Bottom-up DP
        for (int i = 1; i < n; i++) {
            // First, find the minimum and second minimum of the previous row
            int min1 = INT_MAX, min2 = INT_MAX, min1_idx = -1;
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                    min1_idx = j;
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }

            // Now update the current row
            for (int j = 0; j < n; j++) {
                if (j == min1_idx)
                    dp[i][j] += min2; // Use second minimum if same column
                else
                    dp[i][j] += min1; // Use first minimum otherwise
            }
        }

        // Answer is minimum of last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int minSum = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(n, -1));

        // for (int j = 0; j < n; ++j)
        //     minSum = min(minSum, solveME(grid, 0, j, dp));

        // return minSum;
        return bottomUpDP(grid);

    }
};
