class Solution {
public:
    int solveRE(int i, int remaining_walls, vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        if (remaining_walls <= 0) return 0;      // base case: all walls painted
        
        if (i == n) return 1e9;                 // base case: ran out of options

        // Option 1: Take current wall (use paid painter)
        int take = cost[i] + solveRE(i + 1, remaining_walls - (1 + time[i]), cost, time);

        // Option 2: Skip current wall
        int skip = solveRE(i + 1, remaining_walls, cost, time);

        return min(take, skip);
    }

    int solveME(int i, int remaining_walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        int n = cost.size();

        if (remaining_walls <= 0) return 0;

        if (i == n) return 1e9;

        if (dp[i][remaining_walls] != -1) return dp[i][remaining_walls];

        int take = cost[i] + solveME(i + 1, remaining_walls - (1 + time[i]), cost, time, dp);

        int skip = solveME(i + 1, remaining_walls, cost, time, dp);

        return dp[i][remaining_walls] = min(take, skip);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // return solveRE(0, n, cost, time);   
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // dp[i][remaining]
        return solveME(0, n, cost, time, dp);
    }
};
