class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[100001][2][3];     // dp[n][A][L]
    
    int solveME(int n, int A, int L) {
        // invalid cases
        if (A >= 2 || L >= 3)
            return 0;

        // valid string formed
        if (n == 0)
            return 1;

        if (dp[n][A][L] != -1)
            return dp[n][A][L];

        long long ans = 0;

        // Append 'P'
        ans = (ans + solveME(n - 1, A, 0)) % MOD;

        // Append 'A'
        ans = (ans + solveME(n - 1, A + 1, 0)) % MOD;

        // Append 'L'
        ans = (ans + solveME(n - 1, A, L + 1)) % MOD;

        return dp[n][A][L] = ans;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solveME(n, 0, 0);
    }
};