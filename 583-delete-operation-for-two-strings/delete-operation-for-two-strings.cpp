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
            dp[i][j] = 1 + solveME(a, b, i + 1, j + 1, dp);
        else
            dp[i][j] =
                max(solveME(a, b, i, j + 1, dp), solveME(a, b, i + 1, j, dp));
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int lcs_length = solveME(word1, word2, 0, 0, dp);

        return m + n - 2 * lcs_length;
    }
};
/*    FORMULA USED :-
min deletions = (word1.length() - LCS) + (word2.length() - LCS)
              = word1.length() + word2.length() - 2 * LCS
*/
