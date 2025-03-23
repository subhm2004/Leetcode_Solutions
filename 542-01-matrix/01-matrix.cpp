class Solution {
public:
    void bfs(vector<vector<int>>& mat, queue<pair<int, int>>& q, int m, int n) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int x = i + dx, y = j + dy;
                
                // Check if inside bounds and unvisited
                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == -1) {
                    mat[x][y] = mat[i][j] + 1;
                q.push({x, y});     
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        // Initialize queue and mark non-zero cells as -1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0)
                    q.emplace(i, j); // Start BFS from all 0s
                else
                    mat[i][j] = -1; // Mark as unvisited
            }
        }

        // Call BFS function
        bfs(mat, q, m, n);
        return mat;
    }
};
