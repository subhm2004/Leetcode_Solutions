// class Solution {
// public:
//     void bfs(vector<vector<int>>& land, int i, int j, int& x, int& y,
//              vector<pair<int, int>>& directions) {
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         land[i][j] = 2; // Mark as visited.

//         while (!q.empty()) {
//             auto [r, c] = q.front();
//             q.pop();
//             x = max(x, r);
//             y = max(y, c);

//             for (auto& [dr, dc] : directions) {
//                 int nr = r + dr;
//                 int nc = c + dc;
//                 if (nr < land.size() && nc < land[0].size() &&
//                     land[nr][nc] == 1) {
//                     land[nr][nc] = 2; // Mark as visited.
//                     q.push({nr, nc});
//                 }
//             }
//         }
//     }
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>> ans;
//         int m = land.size();
//         int n = land[0].size();
//         vector<pair<int, int>> directions = {{1, 0}, {0, 1}};

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (land[i][j] == 1) {
//                     int x = i, y = j;
//                     bfs(land, i, j, x, y, directions);
//                     ans.push_back({i, j, x, y});
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int& x, int& y,
             vector<pair<int, int>>& directions) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() ||
            land[i][j] != 1)
            return;

        land[i][j] = 2; // Mark as visited.
        x = max(x, i);
        y = max(y, j);

        for (auto& [dr, dc] : directions) {
            dfs(land, i + dr, j + dc, x, y, directions);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int x = i, y = j;
                    dfs(land, i, j, x, y, directions);
                    ans.push_back({i, j, x, y});
                }
            }
        }
        return ans;
    }
};
