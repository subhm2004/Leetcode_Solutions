class Solution {
public:
    int solveRE(int i, int daysLeft, const vector<int>& jobDifficulty, int n) {
        if (daysLeft == 1) {
            int maxDiff = 0;
            for (int k = i; k < n; ++k) {
                maxDiff = max(maxDiff, jobDifficulty[k]);
            }
            return maxDiff;
        }

        int maxToday = 0;
        int minTotal = INT_MAX;

        for (int j = i; j <= n - daysLeft; ++j) {
            maxToday = max(maxToday, jobDifficulty[j]);
            int nextDays = solveRE(j + 1, daysLeft - 1, jobDifficulty, n);
            minTotal = min(minTotal, maxToday + nextDays);
        }

        return minTotal;
    }

    int solveME(int i, int daysLeft, const vector<int>& jobDifficulty, int n, vector<vector<int>>& dp) {
        if (dp[i][daysLeft] != -1) return dp[i][daysLeft];

        if (daysLeft == 1) {
            int maxDiff = 0;
            for (int k = i; k < n; ++k) {
                maxDiff = max(maxDiff, jobDifficulty[k]);
            }
            return dp[i][daysLeft] = maxDiff;
        }

        int maxToday = 0;
        int minTotal = INT_MAX;

        for (int j = i; j <= n - daysLeft; ++j) {
            maxToday = max(maxToday, jobDifficulty[j]);
            int nextDays = solveME(j + 1, daysLeft - 1, jobDifficulty, n, dp);
            minTotal = min(minTotal, maxToday + nextDays);
        }

        return dp[i][daysLeft] = minTotal;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        return solveME(0, d, jobDifficulty, n, dp);
    }
};
