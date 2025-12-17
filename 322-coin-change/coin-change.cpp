class Solution {
public:
    // Recursive Approach (Brute Force)
    int solveRE(vector<int>& coins, int amount) {
        if (amount == 0) return 0;  // Base case: no coins needed
        if (amount < 0) return INT_MAX;  // Invalid case

        int mini = INT_MAX;
        for (int coin : coins) {
            int ans = solveRE(coins, amount - coin);
            if (ans != INT_MAX) {  // Only consider valid result
                mini = min(mini, 1 + ans);
            }
        }
        return mini;
    }

    // Memoization (Top-Down DP)
    int solveME(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];  // Return precomputed result

        int mini = INT_MAX;
        for (int coin : coins) {
            int ans = solveME(coins, amount - coin, dp);
            if (ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }
        return dp[amount] = mini;
    }

    // Tabulation (Bottom-Up DP)
    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);  // Initialize DP array
        dp[0] = 0;  // Base case: No coins needed for 0 amount

        for (int target = 1; target <= amount; target++) {
            for (int coin : coins) {
                if (target >= coin && dp[target - coin] != INT_MAX) {
                    dp[target] = min(dp[target], 1 + dp[target - coin]);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Recursive Solution (Brute Force)
        // int ans = solveRE(coins, amount);
        // return (ans == INT_MAX) ? -1 : ans;

        // Memoization (Optimized)
        vector<int> dp(amount + 1, -1);
        int ans = solveME(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;

        // Tabulation (Optimized DP)
        // return solveTab(coins, amount);
    }
};
