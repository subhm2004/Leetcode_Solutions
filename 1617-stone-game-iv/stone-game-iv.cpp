class Solution {
public:
    int dp[100001];

    bool solve(int n) {

        if (n == 0) return false;   // no move → lose

        if (dp[n] != -1) return dp[n];

        for (int sq = 1; sq * sq <= n; sq++) {

            // opponent loses
            if (solve(n - sq * sq) == false) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};