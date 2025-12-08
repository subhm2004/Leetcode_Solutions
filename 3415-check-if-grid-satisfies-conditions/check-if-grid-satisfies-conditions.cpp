class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // grid[i][j] == grid[i+1][j]
                if (i + 1 < m) {
                    if (grid[i][j] != grid[i+1][j]) 
                        return false;
                }
                
                // grid[i][j] != grid[i][j+1]
                if (j + 1 < n) {
                    if (grid[i][j] == grid[i][j+1]) 
                        return false;
                }
            }
        }
        
        return true;
    }
};
