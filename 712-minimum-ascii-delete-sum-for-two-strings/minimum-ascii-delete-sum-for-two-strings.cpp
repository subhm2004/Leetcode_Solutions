class Solution {
public:
    int solveRE(const string& s1, const string& s2, int i, int j) {
        if (i < 0) { // Delete all remaining characters in s2
            int sum = 0;
            for (int k = 0; k <= j; ++k)
                sum += s2[k];
            return sum;
        }
        if (j < 0) { // Delete all remaining characters in s1
            int sum = 0;
            for (int k = 0; k <= i; ++k)
                sum += s1[k];
            return sum;
        }

        if (s1[i] == s2[j]) // No deletion needed
            return solveRE(s1, s2, i - 1, j - 1);

        // Either delete s1[i] or delete s2[j], take the minimum cost
        return min(solveRE(s1, s2, i - 1, j) + s1[i],
                   solveRE(s1, s2, i, j - 1) + s2[j]);
    }

    int solveME(const string& s1, const string& s2, int i, int j,
                vector<vector<int>>& dp) {
        if (i < 0) {
            int sum = 0;
            for (int k = 0; k <= j; ++k)
                sum += s2[k];
            return sum;
        }
        if (j < 0) {
            int sum = 0;
            for (int k = 0; k <= i; ++k)
                sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = solveME(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = min(solveME(s1, s2, i - 1, j, dp) + s1[i],
                              solveME(s1, s2, i, j - 1, dp) + s2[j]);
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveRE(s1, s2, m - 1, n - 1);
        return solveME(s1, s2, m - 1, n - 1, dp);
    }
};
