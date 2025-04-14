class Solution {
public:
    // transactionsLeft = limit
    // solveRE function jo maximum profit calculate karta hai limited number of transactions ke saath

int solveRE(vector<int>& prices, int i, int buy, int limit) {
    // Base case: Agar koi din bacha nahi ya transactions khatam ho gaye
    if (i >= prices.size() || limit == 0)
        return 0;

    int profit = 0;

    if (buy) {
        // Agar stock kharidna hai to do options hain:
        
        // Option 1: Stock kharid lo is din aur agle din dekh lo (buy = 0)
        int buyItProfit = -prices[i] + solveRE(prices, i + 1, 0, limit);
        
        // Option 2: Skip kar do is din aur agle din dekh lo
        int skipProfit = solveRE(prices, i + 1, 1, limit);
        
        // In dono me se maximum profit choose karo
        profit = max(buyItProfit, skipProfit);
    } else {
        // Agar stock bechna hai to do options hain:
        
        // Option 1: Stock bech do is din, limit ko ek kam karo (limit - 1) aur agle din dekh lo
        int sellItProfit = prices[i] + solveRE(prices, i + 1, 1, limit - 1);
        
        // Option 2: Skip kar do is din aur agle din dekh lo
        int skipProfit = solveRE(prices, i + 1, 0, limit);
        
        // In dono me se maximum profit choose karo
        profit = max(sellItProfit, skipProfit);
    }

    return profit;
}



    int solveME(vector<int>& prices, int i, int buy, int limit,
                       vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || limit == 0)
            return 0;

        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int profit = 0;
        if (buy) {
            int buyItProfit =
                -prices[i] + solveME(prices, i + 1, 0, limit, dp);
            int skipProfit = solveME(prices, i + 1, 1, limit, dp);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit =
                prices[i] + solveME(prices, i + 1, 1, limit - 1, dp);
            int skipProfit = solveME(prices, i + 1, 0, limit, dp);
            profit = max(sellItProfit, skipProfit);
        }

        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveME(
            prices, 0, 1, 2,
            dp); // Start from day 0, buying state, with 2 transactions left
    }
};
