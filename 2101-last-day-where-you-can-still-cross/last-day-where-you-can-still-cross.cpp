class Solution {
public:
    bool multi_source_bfs(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        // pani wale din daal diye 
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // multi-source start: all land cells in first row
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true; // reached bottom

            for (auto &d : direction) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    // int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //     int ans = 0;
    //     for (int day = 1; day <= (int)cells.size(); day++) {
    //         if (multi_source_bfs(row, col, cells, day)) {
    //             ans = day; // update last possible day
    //         } else {
    //             break; // aage ke din bhi possible nahi honge
    //         }
    //     }
    //     return ans;
    // }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (multi_source_bfs(row, col, cells, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
