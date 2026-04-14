// Unbounded Knapsack Counting
class Solution {
public:
    vector<int> coins;
    vector<vector<int>> dp;

    int solve(int i, int amount) {

        if (amount == 0)
            return 1;

        if (i == coins.size())
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int skip = solve(i + 1, amount);

        int take = 0;

        if (coins[i] <= amount)
            take = solve(i, amount - coins[i]); // kitni bhi baar le skte hai coin ko to same rhegi value

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;

        dp.assign(coins.size() + 1, vector<int>(amount + 1, -1));

        return solve(0, amount);
    }
};