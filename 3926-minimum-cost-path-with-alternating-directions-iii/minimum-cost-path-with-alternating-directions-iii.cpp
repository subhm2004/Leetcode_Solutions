class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    ll cellCost(int i, int j) {
        return 1LL * (i + 1) * (j + 1);
    }

    int getId(int i, int j, int n) {
        return i * n + j;
    }

    long long dijkstra(int m, int n, vector<vector<int>>& penalty) {

        int total = m * n;

        vector<vector<ll>> dist(total, vector<ll>(2, INF));

        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > pq;

        dist[0][1] = cellCost(0, 0);
        pq.push({dist[0][1], 0, 1});

        while (!pq.empty()) {

            auto [cost, node, parity] = pq.top();
            pq.pop();

            if (cost != dist[node][parity])
                continue;

            int x = node / n;
            int y = node % n;

            // Wait
            if (dist[node][parity ^ 1] > cost + penalty[x][y]) {
                dist[node][parity ^ 1] = cost + penalty[x][y];
                pq.push({dist[node][parity ^ 1], node, parity ^ 1});
            }

            for (auto [dx, dy] : directions) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                bool legal = false;

                if (parity) {
                    // Odd Action
                    if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1))
                        legal = true;
                } else {
                    // Even Action
                    if ((dx == -1 && dy == 0) || (dx == 0 && dy == -1))
                        legal = true;
                }

                ll newCost = cost + cellCost(nx, ny);

                if (!legal)
                    newCost += penalty[x][y];

                int nextNode = getId(nx, ny, n);

                if (dist[nextNode][parity ^ 1] > newCost) {
                    dist[nextNode][parity ^ 1] = newCost;
                    pq.push({newCost, nextNode, parity ^ 1});
                }
            }
        }

        int target = getId(m - 1, n - 1, n);
        return min(dist[target][0], dist[target][1]);
    }

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        return dijkstra(m, n, penalty);
    }
};