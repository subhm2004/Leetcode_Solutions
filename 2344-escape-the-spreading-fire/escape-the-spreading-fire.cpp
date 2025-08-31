class Solution {
public:
    int m, n;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

     bool is_valid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    // Multi-source BFS - finds shortest distance from any source to all cells
    vector<vector<int>> multi_source_BFS(vector<vector<int>>& grid, vector<pair<int,int>>& sources) {
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        // Initialize all sources with distance 0
        for (auto& src : sources) {
            int x = src.first, y = src.second;
            if (is_valid(x, y) && grid[x][y] != 2) {
                dist[x][y] = 0;
                q.push({x, y});
            }
        }
        
        // BFS traversal
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (is_valid(nx, ny) && grid[nx][ny] != 2 && dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
       
    // Check if person can escape with given wait time
    bool can_escape(int wait_time, vector<vector<int>>& fire_time, vector<vector<int>>& grid) {
        // If fire reaches start before we can start, impossible
        if (wait_time >= fire_time[0][0]) {
            return false;
        }
        
        vector<vector<int>> person_dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        // Start journey after waiting
        person_dist[0][0] = wait_time;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (is_valid(nx, ny) && grid[nx][ny] != 2) {
                    int arriva_time = person_dist[x][y] + 1;
                    
                    // Can move if:
                    // 1. Arrive before fire, OR
                    // 2. Reach destination exactly when fire arrives
                    bool can_move = (arriva_time < fire_time[nx][ny]) || (nx == m-1 && ny == n-1 && arriva_time == fire_time[nx][ny]);
                    
                    if (can_move && arriva_time < person_dist[nx][ny]) {
                        person_dist[nx][ny] = arriva_time;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return person_dist[m-1][n-1] != INT_MAX;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Step 1: Find all fire sources
        vector<pair<int,int>> fire_sources;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire_sources.push_back({i, j});
                }
            }
        }
        
        // Step 2: Calculate fire spread time using multi-source BFS
        vector<vector<int>> fire_time = multi_source_BFS(grid, fire_sources);
        
        // Step 3: Binary search on maximum wait time
        int left = 0, right = 1e9, max_wait_time = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (can_escape(mid, fire_time, grid)) {
                max_wait_time = mid;
                left = mid + 1;  // Try waiting longer
            } else {
                right = mid - 1; // Wait time too long
            }
        }
        
        // Return result according to problem aints
        return (max_wait_time >= 1e9 ) ? 1e9 : max_wait_time;
    }
};

/*
PROBLEM: Escape the Spreading Fire
- Grid: 0=grass, 1=fire, 2=wall
- Find maximum minutes you can wait before starting escape
- Fire spreads to adjacent grass cells every minute
- Must reach bottom-right corner before fire

ALGORITHM:
1. Multi-source BFS from all fire sources to get fire spread times
2. Binary search on wait time [0, 1e9]
3. For each wait time, simulate person's escape using BFS

KEY IMPROVEMENTS:
✓ Used vector<pair<int,int>> directions instead of array
✓ Added is_valid() helper function for cleaner bounds checking
✓ Better variable names (dist -> person_dist, time -> dist)
✓ references where possible for performance
✓ Clear comments explaining logic
✓ Separated concerns with private helper functions

TIME COMPLEXITY: O(log(1e9) * m * n) = O(30 * m * n)
SPACE COMPLEXITY: O(m * n) for distance matrices

GRID VALUES:
0 = grass (can walk)
1 = fire source
2 = wall (blocked)
*/