class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive Approach (Brute Force)
    int solveRE(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        return (2LL * solveRE(n - 1) + solveRE(n - 3)) % MOD;
    }

    // Memoization (Top-Down DP)
    int solveME(int n, vector<int>& dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        if (dp[n] != -1) return dp[n];

        return dp[n] = (2LL * solveME(n - 1, dp) + solveME(n - 3, dp)) % MOD;
    }

    // Tabulation (Bottom-Up DP)
    int solveTab(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }

    // Space Optimized DP (Only storing last 3 values)
    int solveOptimized(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        int prev3 = 1, prev2 = 2, prev1 = 5, curr = 0;

        for (int i = 4; i <= n; i++) {
            curr = (2LL * prev1 + prev3) % MOD;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int numTilings(int n) {
        // Recursive Approach (Brute Force)
        // return solveRE(n);

        // Memoization Approach
        vector<int> dp(n + 1, -1);
        return solveME(n, dp);

        // Tabulation Approach
        // return solveTab(n);

        // Space Optimized Approach
        // return solveOptimized(n);
    }
};
