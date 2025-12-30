class Solution {
public:
    bool is_magic_square(vector<vector<int>>& grid, int i, int j) {
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int nums_map[9] = {0};

        for (int x = 0; x < 3; x++) {
            int row_sum = 0;
            int col_sum = 0;
            for (int y = 0; y < 3; y++) {
                int val = grid[i + x][j + y];
                if (val < 1 || val > 9 || nums_map[val - 1]++) {
                    return false;
                }
                row_sum += val; // (i+x, j+y) → row traversal
                col_sum += grid[i + y][j + x]; // (i+y, j+x) → column traversal
            }
            if (row_sum != sum || col_sum != sum) {
                return false;
            }
        }
        int diagonal = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int anti_diagonal = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        return diagonal == sum && anti_diagonal == sum ;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (is_magic_square(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};