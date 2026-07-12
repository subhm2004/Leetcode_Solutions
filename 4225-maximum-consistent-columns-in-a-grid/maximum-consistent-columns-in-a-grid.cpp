class Solution {
public:
    int m, n, limit;
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    // Check whether prev -> curr transition is valid
    bool isValid(int prev, int curr) {

        for (int row = 0; row < m; row++) {

            if (abs(grid[row][curr] - grid[row][prev]) > limit)
                return false;
        }

        return true;
    }

    int solve(int curr, int prev) {

        // Sare columns dekh liye
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // Option 1 : Current column skip karo
        int notTake = solve(curr + 1, prev);

        // Option 2 : Current column lo
        int take = 0;

        if (prev == -1 || isValid(prev, curr)) {

            take = 1 + solve(curr + 1, curr);
        }

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int maxConsistentColumns(vector<vector<int>>& Grid, int Limit) {

        grid = Grid;
        limit = Limit;

        m = grid.size();
        n = grid[0].size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, -1);
    }
};