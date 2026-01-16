class Solution {
public:
    
    int solveRE(string a, string b, int i, int j) {
        if (i == a.length()) {
            return 0;
        }
        if (j == b.length())
            return 0;

        int ans = 0;
        if (a[i] == b[j])
            ans = 1 + solveRE(a, b, i + 1, j + 1);
        else {
            ans = 0 + max(solveRE(a, b, i, j + 1),
                          solveRE(a, b, i + 1, j));
        }
        return ans;
    }

    int solveME(string &a, string& b, int i, int j,
                      vector<vector<int>>& dp) {
        if (i == a.length()) {
            return 0;
        }
        if (j == b.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j])
            ans = 1 + solveME(a, b, i + 1, j + 1, dp);
        else {
            ans = 0 + max(solveME(a, b, i, j + 1, dp),
                          solveME(a, b, i + 1, j, dp));
        }
        return dp[i][j] = ans;
    }

    int solveUsingTab(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j])
                    ans = 1 + dp[i + 1][j + 1];
                else {
                    ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solveME(text1, text2, i, j, dp);
    }
};