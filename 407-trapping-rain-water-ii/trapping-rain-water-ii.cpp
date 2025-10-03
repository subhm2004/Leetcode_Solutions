class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        if (arr.empty() || arr[0].empty())
            return 0;

        int m = arr.size(), n = arr[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // priority_queue with tuple: (height, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Push boundary cells
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                pq.emplace(arr[i][j], i, j);
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    pq.emplace(arr[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int water_trapped = 0;

        // Process queue
        while (!pq.empty()) {
            auto [height, row, col] = pq.top();  
            pq.pop();

            for (auto [dr, dc] : directions) {  
                int new_row = row + dr;
                int new_col = col + dc;

                if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || visited[new_row][new_col])
                    continue;

                water_trapped += max(0, height - arr[new_row][new_col]);

                pq.emplace(max(height, arr[new_row][new_col]), new_row, new_col);
                visited[new_row][new_col] = true;
            }
        }

        return water_trapped;
    }
};
