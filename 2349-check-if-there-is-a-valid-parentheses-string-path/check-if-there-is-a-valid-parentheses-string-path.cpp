class Solution {
public:
    bool solveRE(vector<vector<char>>& grid, int i, int j, int k) {
        // Agar grid ke bahar chale gaye toh return false
        if (i >= grid.size() || j >= grid[0].size())
            return false;

        // Agar '(' mila toh count badhao, agar ')' mila toh count ghatao
        k += (grid[i][j] == '(') ? 1 : -1;

        // Agar ')' zyada ho gaye kisi bhi point pe toh invalid path hai
        if (k < 0)
            return false;

        // Agar last cell tak pahunch gaye aur '(' aur ')' ka count equal hai
        // toh valid path hai
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return k == 0;

        // Neeche move karne ka option check karo
        bool include = solveRE(grid, i + 1, j, k);
        // Right move karne ka option check karo
        bool exclude = solveRE(grid, i, j + 1, k);

        // Agar kisi bhi path se valid sequence mil gaya toh return true
        return include || exclude;
    }

    bool solveME(vector<vector<char>>& grid, int i, int j, int k,
                 vector<vector<vector<int>>>& dp) {
        if (i >= grid.size() || j >= grid[0].size())
            return false; // Out of bounds

        k += (grid[i][j] == '(') ? 1 : -1;
        if (k < 0)
            return false; // More ')' than '(' at any point

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return k == 0; // Reached end with balanced '(' and ')'

        if (dp[i][j][k] != -1)
            return dp[i][j][k]; // Return cached result

        // Include moving down
        bool include = solveME(grid, i + 1, j, k, dp);
        // Exclude moving right
        bool exclude = solveME(grid, i, j + 1, k, dp);

        return dp[i][j][k] = include || exclude;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        // return solveRE(grid, 0, 0, 0);
        return solveME(grid, 0, 0, 0, dp);
    }
};
