class Solution {
public:
    int m, n; // Grid ki height aur width
    // Char directions - up, right, down, left me move karne ke liye
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    // Check karta hai ki given coordinates valid hai ya nahi
    bool is_valid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    
    // Multi-source BFS - sabhi fire sources se distance calculate karta hai
    // Matlab har cell me fire kab pahunchega, ye calculate karta hai
    vector<vector<int>> multi_source_BFS(vector<vector<int>>& grid, vector<pair<int,int>>& sources) {
        // Distance matrix banate hai - initially sab INT_MAX (infinite)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        // Sabhi fire sources ko queue me daal dete hai with distance 0
        // Kyunki fire already wahan hai, so distance = 0
        for (auto& src : sources) {
            int x = src.first, y = src.second;
            if (is_valid(x, y) && grid[x][y] != 2) { // Wall nahi hona chahiye
                dist[x][y] = 0;
                q.push({x, y});
            }
        }
        
        // BFS traversal - fire ka spread calculate karte hai
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Char directions me check karte hai
            for (auto& dir : directions) {
                int nx = x + dir.first;   // Next x coordinate
                int ny = y + dir.second;  // Next y coordinate
                
                // Agar valid position hai, wall nahi hai, aur abhi tak visit nahi hui
                if (is_valid(nx, ny) && grid[nx][ny] != 2 && dist[nx][ny] == INT_MAX) {
                    // Fire yahan 1 minute baad pahunchega
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist; // Har cell me fire kab pahunchega, ye return karte hai
    }
       
    // Check karta hai ki given wait_time ke saath escape possible hai ya nahi
    bool can_escape(int wait_time, vector<vector<int>>& fire_time, vector<vector<int>>& grid) {
        // Agar fire start position pe wait_time se pehle aa jaye, to impossible
        if (wait_time >= fire_time[0][0]) {
            return false;
        }
        
        // Person ki journey track karne ke liye distance matrix
        vector<vector<int>> person_dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        // Wait_time ke baad journey start karte hai
        person_dist[0][0] = wait_time;
        q.push({0, 0});
        
        // Person ki BFS journey
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Char directions me move try karte hai
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (is_valid(nx, ny) && grid[nx][ny] != 2) {
                    // Person yahan kab pahunchega
                    int arriva_time = person_dist[x][y] + 1;
                    
                    // Move kar sakte hai agar:
                    // 1. Fire se pehle pahunch jaaye, YA
                    // 2. Destination pe exactly fire ke saath pahunche (allowed hai)
                    bool can_move = (arriva_time < fire_time[nx][ny]) || 
                                   (nx == m-1 && ny == n-1 && arriva_time == fire_time[nx][ny]);
                    
                    // Agar move kar sakte hai aur better path hai
                    if (can_move && arriva_time < person_dist[nx][ny]) {
                        person_dist[nx][ny] = arriva_time;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        // Check karte hai ki destination pahunch gaye ya nahi
        return person_dist[m-1][n-1] != INT_MAX;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();    // Grid ki height
        n = grid[0].size(); // Grid ki width
        
        // Step 1: Sabhi fire sources dhundte hai
        // Grid me 1 matlab fire source
        vector<pair<int,int>> fire_sources;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire_sources.push_back({i, j});
                }
            }
        }
        
        // Step 2: Fire spread time calculate karte hai
        // Har cell me fire kab pahunchega, ye nikaalte hai
        vector<vector<int>> fire_time = multi_source_BFS(grid, fire_sources);
        
        // Step 3: Binary search for maximum wait time
        // 0 se 1e9 tak search karte hai
        int left = 0, right = 1e9, max_wait_time = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Overflow avoid karne ke liye
            
            // Agar mid minutes wait kar sakte hai
            if (can_escape(mid, fire_time, grid)) {
                max_wait_time = mid;    // Possible hai, to save kar lete hai
                left = mid + 1;         // Aur zyada wait try karte hai
            } else {
                right = mid - 1;        // Wait time zyada hai, kam karte hai
            }
        }
        
        // Problem ke according result return karte hai
        // Agar bohot zyada wait kar sakte hai to 1e9 return karte hai
        return (max_wait_time >= 1e9) ? 1e9 : max_wait_time;
    }
};

/*
PROBLEM EXPLANATION (Hinglish me):
- Grid diya hai jisme 0=grass, 1=fire, 2=wall
- Tumhe top-left se bottom-right jana hai
- Fire har minute adjacent grass cells me spread hota hai
- Maximum kitne minutes wait kar sakte ho starting se pehle?

ALGORITHM KA BREAKDOWN:
1. Pehle fire ka spread pattern nikaalte hai (multi-source BFS se)
2. Phir binary search karte hai maximum wait time pe
3. Har wait time ke liye check karte hai ki escape possible hai ya nahi

KEY POINTS:
✓ Multi-source BFS use kiya hai fire spread ke liye (efficient)
✓ Binary search optimization for time complexity
✓ Edge case handle kiya hai - destination pe fire ke saath reach kar sakte hai
✓ Clean code structure with helper functions

TIME COMPLEXITY: O(log(1e9) * m * n) = O(30 * m * n)
SPACE COMPLEXITY: O(m * n) distance matrices ke liye

GRID VALUES:
0 = grass (chal sakte hai)
1 = fire source (starting fire)
2 = wall (blocked, nahi ja sakte)
*/