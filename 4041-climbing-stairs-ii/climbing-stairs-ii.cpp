class Solution {
public:
    vector<int> dp;
    int solveME(int idx, int n, vector<int>& arr) {
        // BC
        if (idx == n)
            return 0;
        if (idx > n)
            return INT_MAX;
        if (dp[idx] != -1)
            return dp[idx];

        int mini = INT_MAX;

        for (int step = 1; step <= 3; step++) {
            int next_step = idx + step;
            if (next_step <= n) {
                int jump_cost = arr[next_step - 1] + step * step;
                int future_cost = solveME(next_step, n, arr);
                if (future_cost != INT_MAX) {
                    mini = min(mini, jump_cost + future_cost);
                }
            }
        }
        return dp[idx] = mini;
    }
    int climbStairs(int n, vector<int>& arr) {
        dp.assign(n + 1, -1);
        return solveME(0, n, arr);
    }
};