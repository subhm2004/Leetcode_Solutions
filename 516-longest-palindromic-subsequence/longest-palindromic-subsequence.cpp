class Solution {
public:
    int solveRE(string& a, string& b, int i, int j) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }

        if (a[i] == b[j])
            return 1 + solveRE(a, b, i + 1, j + 1);
        else
            
            return max(solveRE(a, b, i, j + 1), solveRE(a, b, i + 1, j));
    }

    int solveME(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + solveME(a, b, i + 1, j + 1, dp);
        else
            return dp[i][j] = max(solveME(a, b, i, j + 1, dp),
                                  solveME(a, b, i + 1, j, dp));
    }

    int solveUsingTab(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(), s.end());
        string b = s;
        vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));

        // return solveRE(a, b, 0, 0);
        return solveME(a, b, 0, 0, dp);
    }
};
