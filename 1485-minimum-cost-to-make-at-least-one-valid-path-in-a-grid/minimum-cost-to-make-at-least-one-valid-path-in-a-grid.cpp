class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Stores the minimum cost to reach each cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        
        // Min-heap to process cells in increasing order of cost
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Directions: right, left, down, up
        const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Start from (0,0) with cost 0
        pq.emplace(0, 0, 0);
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [currCost, x, y] = pq.top();
            pq.pop();

            // If we reached the bottom-right cell, return the cost
            if (x == m - 1 && y == n - 1) {
                return currCost;
            }

            // Explore all 4 possible directions
            for (int d = 0; d < 4; ++d) {
                auto [dx, dy] = directions[d];
                int nx = x + dx;
                int ny = y + dy;
                
                // Calculate cost: No additional cost if moving in the preferred direction
                int nextCost = currCost + (d + 1 == grid[x][y] ? 0 : 1);

                // If the new position is within bounds and offers a lower cost, update it
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && nextCost < cost[nx][ny]) {
                    cost[nx][ny] = nextCost;
                    pq.emplace(nextCost, nx, ny);
                }
            }
        }
        return -1; // Should never reach here
    }
};
