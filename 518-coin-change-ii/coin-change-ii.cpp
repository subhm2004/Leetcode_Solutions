class Solution {
public:
    int solveRE(int amount, vector<int>& coins, int index) {
        // Base cases
        if (amount == 0) {
            return 1; // Found a way to get the amount
        }
        if (amount < 0 || index < 0) {
            return 0; // Not possible to get the amount
        }

        // Include the current coin in the amount or exclude it
        int include = solveRE(amount - coins[index], coins, index);
        int exclude = solveRE(amount, coins, index - 1);

        return include + exclude;
    }
    int solveME(int amount, vector<int>& coins, int index,
                           vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || index < 0) {
            return 0;
        }
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int include =
            solveME(amount - coins[index], coins, index, dp);
        int exclude = solveME(amount, coins, index - 1, dp);

        dp[index][amount] = include + exclude;

        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solveME(amount, coins, coins.size() - 1, dp);
    }
};
