class Solution {
public:
    int solveRE(int n) {
        if (n <= 1)
            return 0;
        int max_prod = 0;
        //  splitting `n` into two parts: `i` and `n - i`
        for (int i = 1; i < n; ++i) {
            int product = max(i * (n - i), i * solveRE(n - i));
            max_prod = max(max_prod, product);
        }

        return max_prod;
    }
    int solveME(int n, vector<int>& dp) {
        if (n <= 1)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int max_prod = 0;
        for (int i = 1; i < n; ++i) {
            int product = max(i * (n - i), i * solveME(n - i, dp));
            max_prod = max(max_prod, product);
        }

        return dp[n] = max_prod;
    }
    int integerBreak(int n) {
        // return solveRE(n);

        vector<int> dp(n + 1, -1);
        return solveME(n, dp);
    }
};
