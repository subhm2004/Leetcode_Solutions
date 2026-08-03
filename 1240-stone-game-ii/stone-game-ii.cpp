class Solution {
public:
    int dp[101][101][2];

    int solveME(vector<int>& piles, int i, int M, bool alice) {
        if (i == piles.size())
            return 0;

        if (dp[i][M][alice] != -1)
            return dp[i][M][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++) {
            if (i + X - 1 >= piles.size())
                break;

            total += piles[i + X - 1];

            if (alice)
                ans = max(ans, total + solveME(piles, i + X, max(M, X), 0));
            else
                ans = min(ans, solveME(piles, i + X, max(M, X), 1));
        }

        return dp[i][M][alice] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solveME(piles, 0, 1, 1);
    }
};