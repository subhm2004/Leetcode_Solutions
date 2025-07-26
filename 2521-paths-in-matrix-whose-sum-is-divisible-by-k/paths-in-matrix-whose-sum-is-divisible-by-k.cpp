class Solution {
public:
    int MOD = 1e9 + 7;
    int m, n, k;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int sum, vector<vector<int>>& grid) {
        if (i >= m || j >= n)
            return 0;

        sum += grid[i][j];
        int remainder = sum % k;

        if (dp[i][j][remainder] != -1)
            return dp[i][j][remainder];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][remainder] = (remainder == 0 ? 1 : 0);

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
        int ways = 0;

        for (auto [dx, dy] : directions) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni < m && nj < n) {
                ways = (ways + dfs(ni, nj, sum, grid)) % MOD;
            }
        }

        return dp[i][j][remainder] = ways;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = k;

        dp = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(k, -1)));

        return dfs(0, 0, 0, grid);
    }
};
