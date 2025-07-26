class Solution {
public:
    int MOD = 1e9 + 7;
    int m, n, k;
    vector<vector<vector<int>>> dp;
    vector<vector<int>>* grid;
    
    int dfs(int i, int j, int remainder) {
        if (i >= m || j >= n) return 0;
        
        if (dp[i][j][remainder] != -1) return dp[i][j][remainder];
        
         int new_remainder = (remainder + (*grid)[i][j]) % k;
        
        if (i == m - 1 && j == n - 1) {
            return dp[i][j][remainder] = (new_remainder == 0 ? 1 : 0);
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}};  
        int ways = 0;
        
        for (auto [dx, dy] : directions) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni < m && nj < n) {
                ways = (ways + dfs(ni, nj, new_remainder)) % MOD;
            }
        }
        
        return dp[i][j][remainder] = ways;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = k;
        this->grid = &grid;
        
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
        
        return dfs(0, 0, 0);
    }
};