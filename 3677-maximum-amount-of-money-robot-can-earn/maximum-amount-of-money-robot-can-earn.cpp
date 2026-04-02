class Solution {
public:
    int m, n;
    vector<vector<int>> arr;
    int dp[501][501][3];

    int solve(int i, int j, int k) {
        // out of bound
        if (i >= m || j >= n)
            return INT_MIN / 2;
        // destination
        if (i == m - 1 && j == n - 1) {
            if (arr[i][j] < 0 && k > 0)
                return 0;
            return arr[i][j];
        }
        if (dp[i][j][k] != -1e9)
            return dp[i][j][k];
        int ans = 0;
        // normal case
        ans = arr[i][j] + max(solve(i, j + 1, k), // right
                              solve(i + 1, j, k)  // down
                          );

        // robbed case
        if (arr[i][j] < 0 && k > 0) {
            ans = max({
                ans, solve(i, j + 1, k - 1), // right
                solve(i + 1, j, k - 1)       // down
            });
        }
        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        arr = coins;
        this->m = arr.size();
        this->n = arr[0].size();
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1e9;
                }
            }
        }
        return solve(0, 0, 2);
    }
};