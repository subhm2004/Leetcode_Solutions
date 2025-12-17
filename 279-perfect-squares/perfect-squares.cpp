class Solution {
public:
 int solveRE(int n) {
        if (n == 0) return 0; // Base case

        int min_count = INT_MAX;

        for (int i = 1; i * i <= n; ++i) {
            min_count = min(min_count, 1 + solveRE(n - i * i)); // Recursive call
        }

        return min_count;
    }
    int solveME(int n, vector<int>& dp) {
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int min_count = INT_MAX;

        for (int i = 1; i * i <= n; ++i) {
            min_count = min(min_count, 1 + solveME(n - i * i, dp));
        }

        return dp[n] = min_count;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);  
        return solveME(n, dp);
    }
};
