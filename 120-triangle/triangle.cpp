class Solution {
public:
    int solveRE(int i, int j, vector<vector<int>>& arr) {
        if (i == arr.size() - 1) {
            return arr[i][j]; // Base case: last row
        }
        
        int down = solveRE(i + 1, j, arr);
        int diagonal = solveRE(i + 1, j + 1, arr);
        
        return arr[i][j] + min(down, diagonal);
    }

    int solveME(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (i == arr.size() - 1) {
            return arr[i][j]; // Base case: last row
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return precomputed result
        }
        
        int down = solveME(i + 1, j, arr, dp);
        int diagonal = solveME(i + 1, j + 1, arr, dp);
        
        return dp[i][j] = arr[i][j] + min(down, diagonal);
    }

    int solve_bottom_up(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        
        // Initialize last row (base case)
        for (int j = 0; j < n; j++) {
            dp[j] = arr[n-1][j];
        }
        
        // Bottom-up approach: start from second last row
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // dp[j] currently has value from row i+1, position j
                // dp[j+1] has value from row i+1, position j+1
                dp[j] = arr[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }
    int minimumTotal(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        // return solveME(0, 0, arr, dp);
        return solve_bottom_up(arr);
    }
};
