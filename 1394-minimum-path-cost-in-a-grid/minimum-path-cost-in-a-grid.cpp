using T = tuple<int, int, int>;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        for (int j = 0; j < n; j++) {
            dist[0][j] = grid[0][j];
            pq.push({dist[0][j], 0, j});
        }

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (cost > dist[x][y])
                continue;

            if (x == m - 1)
                continue;

            int val = grid[x][y];

            for (int ny = 0; ny < n; ny++) {
                int new_cost = cost + moveCost[val][ny] + grid[x + 1][ny];

                if (new_cost < dist[x + 1][ny]) {
                    dist[x + 1][ny] = new_cost;
                    pq.push({new_cost, x + 1, ny});
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, dist[m - 1][j]);

        return ans;
    }
};