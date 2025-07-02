class Solution {
public:

    int solve(int i, int j, const vector<vector<int>>& arr, vector<vector<int>>& dp) {
        // Out of bounds or zero cell can't form any square
        if (i < 0 || j < 0) return 0;

        if (arr[i][j] == 0) {
            return dp[i][j] = 0;
        }

        // Base Case: first row or column
        if (i == 0 || j == 0) {
            return dp[i][j] = 1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int left     = solve(i, j - 1, arr, dp);
        int top      = solve(i - 1, j, arr, dp);
        int diagonal = solve(i - 1, j - 1, arr, dp);

        return dp[i][j] = min({left, top, diagonal}) + 1;
    }

    int countSquares(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();

        // Initialize dp table with -1
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int totalCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                totalCount += solve(i, j, arr, dp);
            }
        }

        return totalCount;
    }
};
