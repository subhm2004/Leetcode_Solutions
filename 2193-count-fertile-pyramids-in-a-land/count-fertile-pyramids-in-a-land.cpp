class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> dp_down, dp_up;

    int height_down(int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (grid[r][c] == 0) return 0;
        if (dp_down[r][c] != -1) return dp_down[r][c];
        if (r == m - 1) return dp_down[r][c] = 1;  
        int h1 = height_down(r + 1, c - 1);
        int h2 = height_down(r + 1, c);
        int h3 = height_down(r + 1, c + 1);
        return dp_down[r][c] = 1 + min({h1, h2, h3});
    }

    int height_up(int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (grid[r][c] == 0) return 0;
        if (dp_up[r][c] != -1) return dp_up[r][c];
        if (r == 0) return dp_up[r][c] = 1;  
        int h1 = height_up(r - 1, c - 1);
        int h2 = height_up(r - 1, c);
        int h3 = height_up(r - 1, c + 1);
        return dp_up[r][c] = 1 + min({h1, h2, h3});
    }

    int countPyramids(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();
        dp_down.assign(m, vector<int>(n, -1));
        dp_up.assign(m, vector<int>(n, -1));

        int total = 0;

        // normal pyramids
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int h = height_down(r, c);
                if (h >= 2) total += (h - 1);
            }
        }

        // inverse pyramids
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int h = height_up(r, c);
                if (h >= 2) total += (h - 1);
            }
        }

        return total;
    }
};
