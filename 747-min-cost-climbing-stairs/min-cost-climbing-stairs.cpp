class Solution {
public:
    int solveRE(vector<int>& cost, int i) {
        if (i < 0)
            return 0;
        if (i < 2)
            return cost[i];
        return cost[i] + min(solveRE(cost, i - 1), solveRE(cost, i - 2));
    }

    int solveME(vector<int>& cost, vector<int>& dp, int i) {
        if (i < 0)
            return 0;
        if (i < 2)
            return cost[i];
        if (dp[i] != -1)
            return dp[i];

       return dp[i] = cost[i] +
                min(solveME(cost, dp, i - 1), solveME(cost, dp, i - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        return min(solveME(cost, dp, cost.size() - 1),
                   solveME(cost, dp, cost.size() - 2));
    }
};
