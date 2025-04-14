class Solution {
public:


    // solveRE function ek recursive solution hai jo maximum profit calculate karta hai
// Jab 'buy' 1 hota hai, iska matlab hai ki hum stock kharidne ka soch rahe hain
// Toh do options hain:
// 1. Stock kharid lein: profit = -prices[i] + next call (buy = 0, kyunki ab humne stock le liya)
// 2. Skip kar dein: profit = next call with same buy = 1
// Jab 'buy' 0 hota hai, iska matlab hai ki hum stock bechne ka soch rahe hain
// Toh do options hain:
// 1. Bech dein: profit = prices[i] - fee + next call (buy = 1, ab dobara kharid sakte hain)
// 2. Skip kar dein: profit = next call with same buy = 0
// Har step pe maximum profit choose karte hain dono options me se

int solveRE(vector<int>& prices, int i, int buy, int fee) {
    // Base case: agar hum array ke end tak pahuch gaye, to koi profit nahi ho sakta
    if (i >= prices.size())
        return 0;

    int profit = 0;

    if (buy) {
        // Agar abhi kharidna hai to do options hain:
        
        // Option 1: stock kharid lein is din, to profit me price ghategi
        int buyitprofit = -prices[i] + solveRE(prices, i + 1, 0, fee);
        
        // Option 2: skip kar dein aur agle din dekh lein
        int skipprofit = solveRE(prices, i + 1, 1, fee);

        // In dono me se jo zyada profit de raha ho usko choose karo
        profit = max(buyitprofit, skipprofit);
    } else {
        // Agar abhi bechna hai to do options hain:
        
        // Option 1: stock bech dein is din, to profit me price add hogi aur fee subtract hogi
        int sellitprofit = prices[i] + solveRE(prices, i + 1, 1, fee) - fee;

        // Option 2: skip kar dein aur agle din dekh lein
        int skipprofit = solveRE(prices, i + 1, 0, fee);

        // In dono me se jo zyada profit de raha ho usko choose karo
        profit = max(sellitprofit, skipprofit);
    }

    return profit;
}


    int solveME(vector<int>& prices, int i, int buy,
                      vector<vector<int>>& dp, int fee) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            int buyitprofit =
                -prices[i] + solveME(prices, i + 1, 0, dp, fee);
            int skipprofit = solveME(prices, i + 1, 1, dp, fee);
            profit = max(buyitprofit, skipprofit);
        } else {
            int sellitprofit =
                prices[i] + solveME(prices, i + 1, 1, dp, fee) - fee;
            int skipprofit = solveME(prices, i + 1, 0, dp, fee);
            profit = max(sellitprofit, skipprofit);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // return solveRE(prices,0,1,fee);
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solveME(prices, 0, 1, dp, fee);
    }
};