class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [currHealth, x, y] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newHealth = currHealth + grid[nx][ny];

                    if (newHealth < dist[nx][ny]) {
                        dist[nx][ny] = newHealth;
                        pq.emplace(newHealth, nx, ny);
                    }
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};