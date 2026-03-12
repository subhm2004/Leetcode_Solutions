class Solution { // Dijkstra's algorithm implemntation
public:
    using T = tuple<int, int, int>; // (obstacles, x, y)

    int minimumObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        while (!pq.empty()) {

            auto [obstacles, x, y] = pq.top();
            pq.pop();

            if (obstacles > dist[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return obstacles;

            for (auto [dx, dy] : dirs) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int new_cost = obstacles + grid[nx][ny];

                    if (new_cost < dist[nx][ny]) {

                        dist[nx][ny] = new_cost;

                        pq.emplace(new_cost, nx, ny);
                    }
                }
            }
        }

        return -1;
    }
};
