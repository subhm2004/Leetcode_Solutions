class Solution {
public:
    int dijkstra(vector<string>& matrix,
                 unordered_map<char, vector<pair<int,int>>>& portal_Positions) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[m - 1][n - 1] == '#') return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<bool> visited(26, false);   

        using T = tuple<int, int, int>; // (distance, row, col)
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!pq.empty()) {
            auto [curr_dist, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1) return curr_dist;
            if (curr_dist > dist[r][c]) continue;

            char ch = matrix[r][c];
            if (ch >= 'A' && ch <= 'Z') {
                int idx = ch - 'A';
                if (!visited[idx]) {
                    visited[idx] = true;
                    for (auto &[pr, pc] : portal_Positions[ch]) {
                        if (curr_dist < dist[pr][pc]) {
                            dist[pr][pc] = curr_dist;
                            pq.emplace(curr_dist, pr, pc); // teleportation is free
                        }
                    }
                }
            }

            for (auto &[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] != '#') {
                    if (curr_dist + 1 < dist[nr][nc]) {
                        dist[nr][nc] = curr_dist + 1;
                        pq.emplace(curr_dist + 1, nr, nc);
                    }
                }
            }
        }

        return -1; // no path found
    }

    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<char, vector<pair<int,int>>> portal_Positions;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    portal_Positions[ch].emplace_back(i, j);
                }
            }
        }

        return dijkstra(matrix, portal_Positions);
    }
};
