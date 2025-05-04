class Solution {
public:
    int solveRE_LCS(string& a, string& b, int i, int j) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }
        if (a[i] == b[j]) {
            return 1 + solveRE_LCS(a, b, i + 1, j + 1);
        } else {
            int option1 = solveRE_LCS(a, b, i + 1, j);
            int option2 = solveRE_LCS(a, b, i, j + 1);
            return max(option1, option2);
        }
    }

    int solveME_LCS(string& a, string& b, int i, int j,
                    vector<vector<int>>& dp) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (a[i] == b[j]) {
            dp[i][j] = 1 + solveME_LCS(a, b, i + 1, j + 1, dp);
        } else {
            int option1 = solveME_LCS(a, b, i + 1, j, dp);
            int option2 = solveME_LCS(a, b, i, j + 1, dp);
            dp[i][j] = max(option1, option2);
        }
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        solveME_LCS(str1, str2, 0, 0, dp);
        string ans = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i == m) {
                ans += str2[j++];
            } else if (j == n) {
                ans += str1[i++];
            } else if (str1[i] == str2[j]) {
                ans += str1[i++];
                j++;
            } else {
                if (dp[i + 1][j] >= dp[i][j + 1]) {
                    ans += str1[i++];
                } else {
                    ans += str2[j++];
                }
            }
        }
        return ans;
    }
};
