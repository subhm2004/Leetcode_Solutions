class Solution {
public:
    int m, n, original_color, new_color;
    vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<int>> visited;
    vector<pair<int,int>> borders;

    void dfs(int x, int y, vector<vector<int>>& grid) {
        visited[x][y] = 1;
        bool is_border = false;

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                is_border = true;
                continue;
            }

            if (grid[nx][ny] != original_color) {
                is_border = true;
            }

            if (!visited[nx][ny] && grid[nx][ny] == original_color) {
                dfs(nx, ny, grid);
            }
        }

        if (is_border) {
            borders.push_back({x, y});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));

        original_color = grid[row][col];
        new_color = color;

        dfs(row, col, grid);

        for (auto &[bx, by] : borders) {
            grid[bx][by] = new_color;
        }
        return grid;
    }
};
