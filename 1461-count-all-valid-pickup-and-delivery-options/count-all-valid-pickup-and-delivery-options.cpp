class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> dp;

    long long solveME(int n) {
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        long long ans = solveME(n - 1) * (2 * n - 1) * n % MOD;
        return dp[n] = ans;
    }

    int countOrders(int n) {
        dp.assign(n + 1, -1);
        return solveME(n);
    }
};