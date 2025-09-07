class Solution {
public:
    int solveRE(vector<int>& arr, int i, int j) {
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int cost = solveRE(arr, i, k) + arr[i] * arr[k] * arr[j] +
                       solveRE(arr, k, j);
            ans = min(ans, cost);
        }
        return ans;
    }

    int solveME(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int cost = solveME(arr, i, k, dp) + arr[i] * arr[k] * arr[j] +
                       solveME(arr, k, j, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solveME(arr, 0, n - 1, dp);
    }
};