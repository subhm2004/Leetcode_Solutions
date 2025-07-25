class Solution {
public:
    int bfs(vector<vector<int>>& arr) {
        int n = arr.size();
        queue<tuple<int, int, int, int>> q; // (row, col, orientation, moves)
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
        // visited[r][c][orientation]

        q.push({0, 0, 0, 0}); // Start from top-left, horizontal, 0 moves
        visited[0][0][0] = true;

        while (!q.empty()) {
            auto [r, c, orient, moves] = q.front();
            q.pop();

            // Reached goal
            if (r == n - 1 && c == n - 2 && orient == 0) return moves;

            // Move Right
            if (orient == 0 && c + 2 < n &&
                arr[r][c + 1] == 0 && arr[r][c + 2] == 0 &&
                !visited[r][c + 1][0]) {
                visited[r][c + 1][0] = true;
                q.push({r, c + 1, 0, moves + 1});
            }

            // Move Down (Horizontal)
            if (orient == 0 && r + 1 < n &&
                arr[r + 1][c] == 0 && arr[r + 1][c + 1] == 0 &&
                !visited[r + 1][c][0]) {
                visited[r + 1][c][0] = true;
                q.push({r + 1, c, 0, moves + 1});
            }

            // Rotate Clockwise
            if (orient == 0 && r + 1 < n &&
                arr[r + 1][c] == 0 && arr[r + 1][c + 1] == 0 &&
                !visited[r][c][1]) {
                visited[r][c][1] = true;
                q.push({r, c, 1, moves + 1});
            }

            // Move Right (Vertical)
            if (orient == 1 && c + 1 < n &&
                arr[r][c + 1] == 0 && arr[r + 1][c + 1] == 0 &&
                !visited[r][c + 1][1]) {
                visited[r][c + 1][1] = true;
                q.push({r, c + 1, 1, moves + 1});
            }

            // Move Down (Vertical)
            if (orient == 1 && r + 2 < n &&
                arr[r + 2][c] == 0 &&
                !visited[r + 1][c][1]) {
                visited[r + 1][c][1] = true;
                q.push({r + 1, c, 1, moves + 1});
            }

            // Rotate Counter-clockwise
            if (orient == 1 && c + 1 < n &&
                arr[r][c + 1] == 0 && arr[r + 1][c + 1] == 0 &&
                !visited[r][c][0]) {
                visited[r][c][0] = true;
                q.push({r, c, 0, moves + 1});
            }
        }

        return -1; // Not reachable
    }

    int minimumMoves(vector<vector<int>>& arr) {
        return bfs(arr);
    }
};
/*

| Action               | Orientation | Cells to Check                 |
| -------------------- | ----------- | ------------------------------ |
| Move right           | Horizontal  | `arr[r][c+2]`                  |
| Move down            | Horizontal  | `arr[r+1][c]`, `arr[r+1][c+1]` |
| Rotate to vertical   | Horizontal  | `arr[r+1][c]`, `arr[r+1][c+1]` |
| Move right           | Vertical    | `arr[r][c+1]`, `arr[r+1][c+1]` |
| Move down            | Vertical    | `arr[r+2][c]`                  |
| Rotate to horizontal | Vertical    | `arr[r][c+1]`, `arr[r+1][c+1]` |

*/