class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    bool horizontal_cut(int row, long long sum, long long total_sum) {
        // Base case: agar hum last row par hai to hum cut nhi kar skte hai
        if (row == m - 1)
            return false;

        // current row ka sum add kro cumulative sum me
        for (int j = 0; j < n; j++) {
            sum += grid[row][j];
        }

        if (sum == total_sum / 2)
            return true;

        // recursive call for next row
        return horizontal_cut(row + 1, sum, total_sum);
    }

    // similarly for column cuts
    bool vertical_Cut(int col, long long sum, long long total_sum) {
        if (col == n - 1)
            return false;

        for (int i = 0; i < m; i++) {
            sum += grid[i][col];
        }

        if (sum == total_sum / 2)
            return true;

        return vertical_Cut(col + 1, sum, total_sum);
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();

        // total sum of elements in matrix
        long long total_sum = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                total_sum += val;
            }
        }
        if (total_sum % 2 != 0)
            return false;

        return horizontal_cut(0, 0, total_sum) || vertical_Cut(0, 0, total_sum);
    }
};
