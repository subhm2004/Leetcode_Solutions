class Solution { // DFS + Binary Search 
public:
    bool DFS_can_reach(vector<vector<int>>& grid, int i, int j, int T, 
                       vector<vector<bool>>& visited) {
        int n = grid.size();
        // boundary check + visited + height check
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > T)
            return false;
        
        // destination reached
        if (i == n - 1 && j == n - 1)
            return true;
        
        visited[i][j] = true;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto [dx,dy] : dirs) {
            if (DFS_can_reach(grid, i+dx, j+dy, T, visited))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = max(grid[0][0], grid[n-1][n-1]), right = n*n - 1;
        int ans = right;  // maximum possible initially

        while (left <= right) {
            int mid = (left + right) >> 1;
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if (DFS_can_reach(grid, 0, 0, mid, visited)) {
                ans = mid;        // mid valid hai, store karo
                right = mid - 1;  // aur chhota try karo
            } else {
                left = mid + 1;   // mid valid nahi hai, bada time try karo
            }
        }
        return ans;
    }
};
