class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int i, int j) {

        if (i >= m || j >= n || grid[i][j] == 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        grid[i][j] = 0;

        return dfs(grid, i + 1, j) || dfs(grid, i, j + 1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        if (!dfs(grid, 0, 0))
            return true;

        grid[0][0] = 1;
        grid[m - 1][n - 1] = 1;

        return !dfs(grid, 0, 0);
    }
};