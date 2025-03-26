class Solution {
public:
    int solveRE(int n, int A, int L, int MOD) {
        if (A >= 2 || L >= 3)
            return 0;
        if (n == 0)
            return 1;

        int ans = 0;
        // Append 'P'
        ans = (ans + solveRE(n - 1, A, 0, MOD)) % MOD;
        // Append 'A'
        ans = (ans + solveRE(n - 1, A + 1, 0, MOD)) % MOD;
        // Append 'L'
        ans = (ans + solveRE(n - 1, A, L + 1, MOD)) % MOD;

        return ans;
    }
    int solveME(int n, int A, int L, int MOD, vector<vector<vector<int>>>& dp) {
        if (A >= 2 || L >= 3)
            return 0;
        if (n == 0)
            return 1;

        if (dp[n][A][L] != -1)
            return dp[n][A][L];

        int ans = 0;
        ans = (ans + solveME(n - 1, A, 0, MOD, dp)) % MOD;
        ans = (ans + solveME(n - 1, A + 1, 0, MOD, dp)) % MOD;
        ans = (ans + solveME(n - 1, A, L + 1, MOD, dp)) % MOD;

        return dp[n][A][L] = ans;
    }

    int checkRecord(int n) {
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveME(n, 0, 0, MOD, dp);
    }
};
