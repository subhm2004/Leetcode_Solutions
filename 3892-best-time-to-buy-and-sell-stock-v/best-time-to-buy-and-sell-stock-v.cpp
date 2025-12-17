class Solution {
public:
    long long dp[1001][501][3];

    // case_:
    // 0 -> No stock held (neutral)
    // 1 -> Bought (normal transaction, waiting to sell)
    // 2 -> Short sold (waiting to buy back)

    long long solveME(int i, int k, int case_, vector<int>& prices) {

        if (i == prices.size()) {
            if (case_ == 0)
                return 0;
            return INT_MIN; // unfinished transaction is invalid
        }

        if (dp[i][k][case_] != INT_MIN)
            return dp[i][k][case_];

        long long take = INT_MIN;
        long long dontTake = solveME(i + 1, k, case_, prices);

        if (k > 0) {
            if (case_ == 1) {
                // sell (complete normal transaction)
                take = prices[i] + solveME(i + 1, k - 1, 0, prices);
            }
            else if (case_ == 2) {
                // buy back (complete short transaction)
                take = -prices[i] + solveME(i + 1, k - 1, 0, prices);
            }
            else {
                // case_ == 0 → start transaction
                take = max(
                    -prices[i] + solveME(i + 1, k, 1, prices), // buy
                     prices[i] + solveME(i + 1, k, 2, prices)  // short sell
                );
            }
        }

        return dp[i][k][case_] = max(take, dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int c = 0; c < 3; c++)
                    dp[i][j][c] = INT_MIN;

        return solveME(0, k, 0, prices);
    }
};
