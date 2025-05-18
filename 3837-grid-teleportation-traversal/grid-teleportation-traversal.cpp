class Solution {
public:
    int dijkstra(const vector<string>& matrix,
                 unordered_map<char, vector<pair<int,int>>>& portal_Positions) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[m - 1][n - 1] == '#') return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        unordered_set<char> used_Portals;

        using T = tuple<int, int, int>; // (distance, row, col)
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!pq.empty()) {
            auto [currDist, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1) return currDist;
            if (currDist > dist[r][c]) continue;

            char ch = matrix[r][c];
            if (ch >= 'A' && ch <= 'Z' && used_Portals.find(ch) == used_Portals.end()) {
                used_Portals.insert(ch);
                for (auto &[pr, pc] : portal_Positions[ch]) {
                    if (currDist < dist[pr][pc]) {
                        dist[pr][pc] = currDist;
                        pq.emplace(currDist, pr, pc); // teleportation me cost nhi lagti acc to problem
                    }
                }
            }

            for (auto &[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] != '#') {
                    if (currDist + 1 < dist[nr][nc]) {
                        dist[nr][nc] = currDist + 1;
                        pq.emplace(currDist + 1, nr, nc);
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
