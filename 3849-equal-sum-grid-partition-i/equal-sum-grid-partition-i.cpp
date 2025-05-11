class Solution {
public:
    // Helper function to check horizontal cuts recursively
    bool horizontalCutHelper(vector<vector<int>>& grid, int m, int n, int row, long long sum, long long total) {
        // Base case: if we are at the last row, can't cut here
        if (row == m - 1) return false;
        
        // Add the current row's sum to the cumulative sum
        for (int j = 0; j < n; ++j) {
            sum += grid[row][j];
        }

        // Check if the sum of the first section equals half the total sum
        if (sum * 2 == total) return true;

        // Recurse to check the next row
        return horizontalCutHelper(grid, m, n, row + 1, sum, total);
    }

    // Helper function to check vertical cuts recursively
    bool verticalCutHelper(vector<vector<int>>& grid, int m, int n, int col, long long sum, long long total) {
        // Base case: if we are at the last column, can't cut here
        if (col == n - 1) return false;

        // Add the current column's sum to the cumulative sum
        for (int i = 0; i < m; ++i) {
            sum += grid[i][col];
        }

        // Check if the sum of the first section equals half the total sum
        if (sum * 2 == total) return true;

        // Recurse to check the next column
        return verticalCutHelper(grid, m, n, col + 1, sum, total);
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total sum of all elements in the grid (use long long to avoid overflow)
        long long total = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        // Try horizontal and vertical cuts
        return horizontalCutHelper(grid, m, n, 0, 0, total) || verticalCutHelper(grid, m, n, 0, 0, total);
    }
};
