class Solution {
public:
    double solveME(int n, vector<double>& dp) {
        if (n == 1)
            return 1.0;
        if (n == 2)
            return 0.5;
        if (dp[n] >= 0)
            return dp[n];

        double prev = solveME(n - 1, dp);
        return dp[n] = (1.0 + (n - 2) * prev) / n;
    }

    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(n + 1, -1.0);
        return solveME(n, dp);
    }
};
