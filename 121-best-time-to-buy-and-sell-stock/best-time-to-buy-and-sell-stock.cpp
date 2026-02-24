class Solution {
public:
    vector<int> prices;     
    int dp[100005];

    int solve(int idx, int min_price) {

        if (idx == prices.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        min_price = min(min_price, prices[idx]);

        int profit = prices[idx] - min_price;

        return dp[idx] = max(profit, solve(idx + 1, min_price));
    }

    int maxProfit(vector<int>& prices) {

        this-> prices = prices;                 
        memset(dp, -1, sizeof(dp));

        return solve(0, INT_MAX);
    }
};