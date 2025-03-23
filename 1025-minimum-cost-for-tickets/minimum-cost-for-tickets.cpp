class Solution {
public:
    // Recursive Approach (Brute Force)
    int solveRE(vector<int>& days, vector<int>& costs, int i) {
        if (i >= days.size())
            return 0;

        int cost1 = costs[0] + solveRE(days, costs, i + 1);

        int EndDayPass = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= EndDayPass) {
            j++;
        }
        int cost7 = costs[1] + solveRE(days, costs, j);

        EndDayPass = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= EndDayPass) {
            j++;
        }
        int cost30 = costs[2] + solveRE(days, costs, j);

        return min({cost1, cost7, cost30});
    }

    // Memoized Approach (Optimized)
    int solveME(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if (i >= days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int cost1 = costs[0] + solveME(days, costs, i + 1, dp);

        int EndDayPass = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= EndDayPass) {
            j++;
        }
        int cost7 = costs[1] + solveME(days, costs, j, dp);

        EndDayPass = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= EndDayPass) {
            j++;
        }
        int cost30 = costs[2] + solveME(days, costs, j, dp);

        return dp[i] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        // Recursive approach
        // return solveRE(days, costs, 0);

        // Memoized approach
        vector<int> dp(n + 1, -1);
        return solveME(days, costs, 0, dp);
    }
};
