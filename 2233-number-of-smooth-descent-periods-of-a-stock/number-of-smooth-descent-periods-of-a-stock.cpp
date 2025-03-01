class Solution {
public:
    long long solveRE(int i, vector<int>& prices) {
        if (i == 0)
            return 1; // Base case: single element

        if (prices[i] == prices[i - 1] - 1)
            return solveRE(i - 1, prices) + 1;

        return 1; // Restart at 1 if sequence breaks
    }

    long long solveME(int i, vector<int>& prices, vector<long long>& dp) {
        if (i == 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        if (prices[i] == prices[i - 1] - 1)
            return dp[i] = solveME(i - 1, prices, dp) + 1;

        return dp[i] = 1;
    }

    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n, -1);

        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += solveME(i, prices, dp);

        return ans;
    }
};