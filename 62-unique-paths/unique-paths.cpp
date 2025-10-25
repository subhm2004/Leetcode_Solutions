class Solution {
public:
    int solveRE(int i, int j, int m, int n) {
        // Base cases
        if (i >= m || j >= n) {
            return 0; // Out of bounds
        }
        if (i == m - 1 && j == n - 1) {
            return 1; // Reached the destination
        }

        int right_path = solveRE(i, j + 1, m, n);
        int down_path = solveRE(i + 1, j, m, n);

        return right_path + down_path;
    }

    int solveME(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // Base cases
        if (i >= m || j >= n) {
            return 0; // Out of bounds
        }
        if (i == m - 1 && j == n - 1) {
            return 1; // Reached the destination
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return precomputed result
        }

        int right_path = solveME(i, j + 1, m, n, dp);
        int down_path = solveME(i + 1, j, m, n, dp);

        return dp[i][j] = right_path + down_path;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveME(0, 0, m, n, dp);
    }
};
