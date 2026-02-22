class Solution {
public:
    long long MOD = 1e9 + 7;
    int dp[35][1005];

    long long solveME(int n, int k, int target) {

        // base case
        if (n == 0)
            return (target == 0);

        if (target < 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        long long ans = 0;

        for (int face = 1; face <= k; face++) {
            if (target - face >= 0) {
                ans = (ans + solveME(n - 1, k, target - face)) % MOD;
            }
        }

        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {

        memset(dp, -1, sizeof(dp));
        return solveME(n, k, target);
    }
};