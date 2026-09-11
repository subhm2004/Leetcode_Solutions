class Solution {
public:
    // dist[row][col][last_direction][turns]
    //
    // last_direction:
    // 0 = Up
    // 1 = Down
    // 2 = Left
    // 3 = Right
    // 4 = Start / No direction
    int dist[75][75][5][75];

    int dijkstra(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        const int INF = 1e9;

        // Sabhi states ko INF se initialize karenge.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int dir = 0; dir < 5; dir++) {
                    for (int t = 0; t <= k; t++) {
                        dist[i][j][dir][t] = INF;
                    }
                }
            }
        }

        // Directions:
        // 0 = Up
        // 1 = Down
        // 2 = Left
        // 3 = Right
        vector<vector<int>> directions = {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1}   // Right
        };

        // State: {cost, row, col, last_direction, turnsUsed}
        using State = tuple<int, int, int, int, int>;

        priority_queue<State, vector<State>, greater<>> pq;

        // Starting cell.
        // 4 ka matlab koi previous direction nahi hai.
        dist[0][0][4][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 4, 0});

        while (!pq.empty()) {

            auto [cost, r, c, last_dir, turns] = pq.top();
            pq.pop();

            // Agar ye outdated state hai,
            // to ignore kar do.
            if (cost != dist[r][c][last_dir][turns]) {
                continue;
            }

            // Destination mil gaya.
            if (r == m - 1 && c == n - 1) {
                return cost;
            }

            // 4 directions try karenge.
            for (int new_dir = 0; new_dir < 4; new_dir++) {

                int nr = r + directions[new_dir][0];
                int nc = c + directions[new_dir][1];

                // Grid ke bahar nahi jana.
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                int new_turns = turns;

                // First move par turn nahi hota.
                //
                // Agar previous direction aur
                // current direction different hain,
                // to 1 turn add hoga.
                if (last_dir != 4 && last_dir != new_dir) {
                    new_turns++;
                }

                // At most k turns allowed hain.
                if (new_turns > k) {
                    continue;
                }

                // Next cell ka cost add karenge.
                int new_cost = cost + grid[nr][nc];

                // Better state mila to update.
                if (new_cost < dist[nr][nc][new_dir][new_turns]) {

                    dist[nr][nc][new_dir][new_turns] = new_cost;

                    pq.push({new_cost, nr, nc, new_dir, new_turns});
                }
            }
        }

        // k turns ke andar destination reachable nahi hua.
        return -1;
    }

    int minCost(vector<vector<int>>& grid, int k) { return dijkstra(grid, k); }
};