class Solution {
public:
    int solveRE(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0; // base case: if we cross stairs
        return cost[i] + min(solveRE(cost, i + 1), solveRE(cost, i + 2));
    }

    int solveME(vector<int>& cost, vector<int>& dp, int i) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(solveME(cost, dp, i + 1), solveME(cost, dp, i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        // return min(solveRE(cost, 0), solveRE(cost, 1));

        return min(solveME(cost, dp, 0), solveME(cost, dp, 1));
    }
};
