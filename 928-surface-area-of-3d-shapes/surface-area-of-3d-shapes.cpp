class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int height = grid[i][j];

                if (height > 0) {
                    area += 6 * height - 2 * (height - 1);
                    
                    if (j + 1 < n)
                        area -= 2 * min(height, grid[i][j + 1]);
                    if (i + 1 < n)
                        area -= 2 * min(height, grid[i + 1][j]);
                }
            }
        }

        return area;
    }
};
