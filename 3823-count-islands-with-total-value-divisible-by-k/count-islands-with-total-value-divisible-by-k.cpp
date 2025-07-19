using ll = long long;

class Solution {
public:
    ll bfs(vector<vector<int>>& grid, int start_i, int start_j, vector<vector<int>>& visited) {
        if (grid[start_i][start_j] == 0 || visited[start_i][start_j]) return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<int, int>> q;
        q.push({start_i, start_j});
        ll sum = grid[start_i][start_j];
        visited[start_i][start_j] = 1;  //  visited mark kro 
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int new_i = i + d[0];
                int new_j = j + d[1];
                
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && 
                    grid[new_i][new_j] > 0 && !visited[new_i][new_j]) {
                    sum += grid[new_i][new_j];
                    visited[new_i][new_j] = 1;  // mark as visited and push in queue
                    q.push({new_i, new_j});
                }
            }
        }
        
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    ll sum = bfs(grid, i, j, visited);
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        
        return count;
    }
};