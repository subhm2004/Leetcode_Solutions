class Solution {
public:
    int solveRE(int n) {
        if (n <= 1)
            return 1;

        return solveRE(n - 1) + solveRE(n - 2);
    }

    int solveME(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solveME(n - 1, dp) + solveME(n - 2, dp);
    }

    int climbStairs(int n) {
        // return solveRE(n);
        vector<int> dp(n + 1, -1);
        return solveME(n, dp);
    }
};
