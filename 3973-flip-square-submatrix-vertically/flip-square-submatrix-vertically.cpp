class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // Vertically flip the k x k submatrix starting at (x, y)
        for (int i = 0; i < k / 2; i++) {
            int top_row = x + i;
            int bottom_row = x + (k - 1 - i);
            for (int col = y; col < y + k; col++) {
                swap(grid[top_row][col], grid[bottom_row][col]);
            }
        }
        return grid;
    }
};
