class Solution {
public:
    string s;
    int dp[105][105];

    int solve(int i, int j) {

        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int min_turns = INT_MAX;

        for (int k = i; k < j; k++) {
            min_turns = min(min_turns, solve(i, k) + solve(k + 1, j));
        }

        if (s[i] == s[j])
            min_turns--;

        return dp[i][j] = min_turns;
    }

    int strangePrinter(string s) {
       this-> s = s;
        memset(dp, -1, sizeof(dp));

        return solve(0, s.size() - 1);
    }
};