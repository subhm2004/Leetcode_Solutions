class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        

        unordered_set<ll> seen;
        ll top = 0;

        for (int i = 0; i < m - 1; i++) {

            for (int j = 0; j < n; j++) {
                seen.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bot  = total - top;
            ll diff = top - bot;

            // Case 1: Equal split
            if (diff == 0) return true;

            // Case 2: Boundary cells
            if (diff == (ll)grid[0][0])   return true;
            if (diff == (ll)grid[0][n-1]) return true;
            if (diff == (ll)grid[i][0]) return true;

            // Case 3: Interior safe cells
            // n > 1 → not a single column
            // i > 0 → at least 2 rows in top section
            if (i > 0 && n > 1 && seen.count(diff)) 
                return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // Horizontal
        if (checkCuts(grid)) 
            return true;

        // Handle removal from bottom section
        reverse(begin(grid), end(grid));

        if (checkCuts(grid)) 
            return true;

        reverse(begin(grid), end(grid)); // restore


        // Vertical → transpose
        vector<vector<int>> transposeGrid(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if (checkCuts(transposeGrid)) 
            return true;

        reverse(begin(transposeGrid), end(transposeGrid));
        
        return checkCuts(transposeGrid);
    }
};