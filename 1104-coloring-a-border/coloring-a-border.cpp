class Solution {
public:
    int m, n, original_color, new_color;
    vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<int>> visited;
    vector<pair<int,int>> borders;

    void bfs(int sr, int sc, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            bool is_border = false;

             for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    is_border = true;
                    continue;
                }

                if (grid[nx][ny] != original_color) {
                    is_border = true;
                }

                if (!visited[nx][ny] && grid[nx][ny] == original_color) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            if (is_border) {
                borders.push_back({x, y});
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));

        original_color = grid[row][col];
        new_color = color;

        bfs(row, col, grid);

        for (auto &[bx, by] : borders) {
            grid[bx][by] = new_color;
        }
        return grid;
    }
};
