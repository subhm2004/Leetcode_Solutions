class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> dp;
    
    bool isValid(int row, int col){
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
    int solve(int row, int col){
        
        if(row == m) return col;
        
        if(dp[row][col] != -2)
            return dp[row][col];
        
        if(grid[row][col] == 1){
            
            if(isValid(row, col+1) && grid[row][col+1] == 1){
                return dp[row][col] = solve(row+1, col+1);
            }
            else{
                return dp[row][col] = -1;
            }
        }
        
        if(grid[row][col] == -1){
            
            if(isValid(row, col-1) && grid[row][col-1] == -1){
                return dp[row][col] = solve(row+1, col-1);
            }
            else{
                return dp[row][col] = -1;
            }
        }
        
        return -1;
    }
    
    
    vector<int> findBall(vector<vector<int>>& g) {
        
        grid = g;
        m = grid.size();
        n = grid[0].size();
        
        dp.assign(m, vector<int>(n, -2));
        
        vector<int> ans(n);
        
        for(int col = 0; col < n; col++){
            ans[col] = solve(0, col);
        }
        
        return ans;
    }
};