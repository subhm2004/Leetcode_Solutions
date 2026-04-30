class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = 0; cost <= k; cost++) {

                    int new_Cost = cost + (grid[i][j] > 0);
                    if (new_Cost > k) continue;

                    // destination
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down = -1, right = -1;

                    if (i + 1 < m)
                        down = dp[i + 1][j][new_Cost];

                    if (j + 1 < n)
                        right = dp[i][j + 1][new_Cost];

                    int best_next = max(down, right);

                    if (best_next != -1) {
                        dp[i][j][cost] = grid[i][j] + best_next;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};