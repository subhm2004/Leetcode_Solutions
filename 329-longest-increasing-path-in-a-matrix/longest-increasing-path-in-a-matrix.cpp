class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];

        int max_length = 1;
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};  

        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[ni][nj] > matrix[i][j]) {
                int len = 1 + dfs(ni, nj, matrix);
                max_length = max(max_length, len);
            }
        }

        return dp[i][j] = max_length;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};