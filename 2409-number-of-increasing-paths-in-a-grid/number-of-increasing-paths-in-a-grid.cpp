class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& arr) {
        if (dp[i][j] != -1) return dp[i][j];

        int count = 1;  // path of (i,j) cell
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n && arr[ni][nj] > arr[i][j]) {
                count = (count + dfs(ni, nj, arr)) % MOD;
            }
        }

        return dp[i][j] = count;
    }

    int countPaths(vector<vector<int>>& arr) {
        m = arr.size();
        n = arr[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));   

        long long total = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                total = (total + dfs(i, j, arr)) % MOD;
            }
        }

        return total;
    }
};
