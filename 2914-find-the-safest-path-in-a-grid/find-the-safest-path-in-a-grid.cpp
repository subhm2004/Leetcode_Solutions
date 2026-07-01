class Solution {
public:
    vector<vector<int>> getDistToThief(const vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distToThief(n, vector<int>(n, -1)); // Saare cells ko initially -1 se mark karenge
        queue<pair<int, int>> q;

        // Multi-source BFS start karenge jahan choro ki positions already known hain
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) { // Agar yahan chor hai toh distance 0 hoga
                    q.emplace(i, j);
                    distToThief[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // BFS ke liye 4 directions

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= n || distToThief[x][y] != -1) 
                    continue; // Agar cell out of bounds ya already processed hai toh skip karo

                distToThief[x][y] = distToThief[i][j] + 1; // Distance update karo
                q.emplace(x, y);
            }
        }

        return distToThief; // Har cell ka nearest chor tak ka distance return hoga
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distToThief = getDistToThief(grid); // Har cell ka nearest chor se distance nikalenge

        // Max-heap (priority queue) use karenge {safeness, x, y}
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(distToThief[0][0], 0, 0); // Starting position dalenge

        vector<vector<bool>> seen(n, vector<bool>(n, false)); // Ek "visited" array maintain karenge
        seen[0][0] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 directions ke liye

        while (!pq.empty()) {
            auto [safeness, i, j] = pq.top();
            pq.pop();

            // Agar last cell pe pahunch gaye toh safeness return kar do
            if (i == n - 1 && j == n - 1) 
                return safeness;

            // 4 directions explore karenge
            for (auto [dx, dy] : directions) {
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= n || seen[x][y]) 
                    continue; // Agar boundary cross kar diya ya pehle visit ho chuka hai toh skip karo

                seen[x][y] = true;
                int newSafeness = min(safeness, distToThief[x][y]); // Yeh ensure karega ki weakest link consider ho
                pq.emplace(newSafeness, x, y);
            }
        }

        return 0; // Yeh kabhi reach nahi hoga
    }
};
