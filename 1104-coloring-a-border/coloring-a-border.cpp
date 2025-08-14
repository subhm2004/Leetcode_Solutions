class Solution {
public:
    // m = rows, n = columns
    // original_color = jo color starting cell ka hai (connected component ka color)
    // new_color = jo color border cells pe lagana hai
    int m, n, original_color, new_color;

    // 4 directions: up, right, down, left
    vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    // visited matrix: taaki ek cell dobara BFS me na aaye
    vector<vector<int>> visited;

    // borders: yaha hum sirf border cells store karenge
    vector<pair<int,int>> borders;

    // BFS function jo connected component traverse karega
    void bfs(int sr, int sc, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        // starting cell ko push karo
        q.push({sr, sc});
        visited[sr][sc] = 1; // mark visited

        while (!q.empty()) {
            // current cell nikaalo
            auto [x, y] = q.front();
            q.pop();

            // ye flag check karega ki current cell border hai ya nahi
            bool is_border = false;

            // 4 directions me check karenge
            for (auto [dx, dy] : directions) {
                int nx = x + dx; // next row
                int ny = y + dy; // next col

                // 1️⃣ Agar grid ke bahar chale gaye -> ye cell border hai
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    is_border = true;
                    continue; // next direction check karo
                }

                // 2️⃣ Agar neighbor ka color alag hai -> ye cell border hai
                if (grid[nx][ny] != original_color) {
                    is_border = true;
                }

                // 3️⃣ Agar neighbor same color ka hai aur visit nahi hua
                if (!visited[nx][ny] && grid[nx][ny] == original_color) {
                    visited[nx][ny] = 1; // mark visited
                    q.push({nx, ny});    // BFS queue me daal do
                }
            }

            // Agar ye cell border nikla -> store kar lo list me
            if (is_border) {
                borders.push_back({x, y});
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();         // total rows
        n = grid[0].size();      // total columns

        // visited matrix initialize karo
        visited.assign(m, vector<int>(n, 0));

        // original component ka color
        original_color = grid[row][col];
        // naya color jo border pe lagana hai
        new_color = color;

        // BFS chalao starting point se
        bfs(row, col, grid);

        // BFS ke baad "borders" list me sirf border cells hai
        // Unka color change kar do
        for (auto &[bx, by] : borders) {
            grid[bx][by] = new_color;
        }

        // final grid return karo
        return grid;
    }
};
