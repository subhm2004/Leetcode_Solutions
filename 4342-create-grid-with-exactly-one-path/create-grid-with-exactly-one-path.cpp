class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        if (m == 1) {
            grid[0] = string(n, '.');
            return grid;
        }

        if (n == 1) {
            for (int i = 0; i < m; i++) grid[i][0] = '.';
            return grid;
        }

        for (int j = 0; j < n; j++) grid[0][j] = '.';
        for (int i = 0; i < m; i++) grid[i][n - 1] = '.';

        return grid;
    }
};