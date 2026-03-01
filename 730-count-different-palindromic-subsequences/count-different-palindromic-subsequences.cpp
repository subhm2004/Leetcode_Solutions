class Solution {
public:
    int countPalindromicSubsequences(string s) {

        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<long long>> dp(
            n, vector<long long>(n, 0));

        // base case
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // interval DP
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] != s[j]) {

                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];

                } else {

                    int low = i + 1;
                    int high = j - 1;

                    while (low <= high && s[low] != s[i])
                        low++;

                    while (low <= high && s[high] != s[i])
                        high--;

                    long long mid = dp[i+1][j-1];

                    if (low > high) {
                        // no same char inside
                        dp[i][j] = 2 * mid + 2;
                    }
                    else if (low == high) {
                        // one same char inside
                        dp[i][j] = 2 * mid + 1;
                    }
                    else {
                        // multiple same chars
                        dp[i][j] = 2 * mid - dp[low+1][high-1];
                    }
                }

                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
            }
        }

        return dp[0][n-1];
    }
};