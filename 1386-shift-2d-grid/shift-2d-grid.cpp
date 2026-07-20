class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total; // k bada ho sakta hai, wrap kar do (Example 3: k=9, total=9 → k=0, grid same)

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Current cell ka flat (1D) index
                int idx = i * n + j;

                // Shift ke baad ye element kahan jayega (circular right shift)
                int newIdx = (idx + k) % total;

                // 1D index ko wapas 2D coordinates me convert karo
                int newRow = newIdx / n;
                int newCol = newIdx % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};