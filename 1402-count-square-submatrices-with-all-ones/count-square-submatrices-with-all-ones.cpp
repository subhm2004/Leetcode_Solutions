class Solution {
public:
    int solveRE(int i, int j, const vector<vector<int>>& arr) {
        // Out of bounds or zero cell can't form any square
        if (i < 0 || j < 0 || arr[i][j] == 0) return 0;

        // Base Case: first row or first column with value 1 can only form 1x1 square
        if (i == 0 || j == 0) return 1;

        int left     = solveRE(i, j - 1, arr);
        int top      = solveRE(i - 1, j, arr);
        int diagonal = solveRE(i - 1, j - 1, arr);

        return min({left, top, diagonal}) + 1;
    }

    int solveME(int i, int j, const vector<vector<int>>& arr, vector<vector<int>>& dp) {
         if (i < 0 || j < 0 || arr[i][j] == 0) return 0;

         if (i == 0 || j == 0) return 1;

         if (dp[i][j] != -1) return dp[i][j];

        int left     = solveME(i, j - 1, arr, dp);
        int top      = solveME(i - 1, j, arr, dp);
        int diagonal = solveME(i - 1, j - 1, arr, dp);

        return dp[i][j] = min({left, top, diagonal}) + 1;
    }

    int countSquares(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int total_count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                total_count += solveME(i, j, arr, dp);
            }
        }

        return total_count;
    }
};
