class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size() - 1, col = 0, count = 0;
        int n = grid[0].size();

        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                count += (n - col); // Is row ke saare elements negative hain
                row--;  // Upar wali row par jao
            } else {
                col++;  // Agle column par jao
            }
        }

        return count;
    }
};
