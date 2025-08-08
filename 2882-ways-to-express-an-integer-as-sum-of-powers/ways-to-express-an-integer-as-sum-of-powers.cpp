class Solution {
public:
    const int MOD = 1e9 + 7;

    int solveRE(int i, int sum, int target, int x) {
        if (sum == target)
            return 1; // Found a valid way
        if (i <= 0 || sum > target)
            return 0; // No valid way

        long long power = pow(i, x);

        if (sum + power > target)
            return solveRE(i - 1, sum, target, x);

        int include = solveRE(i - 1, sum + power, target, x) % MOD;
        int exclude = solveRE(i - 1, sum, target, x) % MOD;

        return (include + exclude) % MOD;
    }

    int solveME(int i, int sum, int target, int x, vector<vector<int>>& dp) {
        if (sum == target)
            return 1;  // Found a valid way
        if (i <= 0 || sum > target)
            return 0;  // No valid way

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long power = pow(i,x);

        if (sum + power > target)
            return dp[i][sum] = solveME(i - 1, sum, target, x, dp);

        int include = solveME(i - 1, sum + power, target, x, dp) % MOD;
        int exclude = solveME(i - 1, sum, target, x, dp) % MOD;

        return dp[i][sum] = (include + exclude) % MOD;
    }

    int numberOfWays(int n, int x) {
        // return solveRE(n, 0, n, x);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveME(n, 0, n, x, dp);
    }
};
