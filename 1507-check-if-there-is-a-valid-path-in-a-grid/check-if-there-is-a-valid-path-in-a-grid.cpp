class Solution {
public:
       bool can_connect(int from_type, int to_type, int direction) {
        bool can_go_from_here = false;
        switch(direction) {
            case 0: // right
                can_go_from_here = (from_type == 1 || from_type == 4 || from_type == 6);
                break;
            case 1: // left
                can_go_from_here = (from_type == 1 || from_type == 3 || from_type == 5);
                break;
            case 2: // down
                can_go_from_here = (from_type == 2 || from_type == 3 || from_type == 4);
                break;
            case 3: // up
                can_go_from_here = (from_type == 2 || from_type == 5 || from_type == 6);
                break;
        }

        bool can_receive_here = false;
        switch(direction) {
            case 0: // left se aa skte
                can_receive_here = (to_type == 1 || to_type == 3 || to_type == 5);
                break;
            case 1: // right se aa skte
                can_receive_here = (to_type == 1 || to_type == 4 || to_type == 6);
                break;
            case 2: // up se aa skte
                can_receive_here = (to_type == 2 || to_type == 5 || to_type == 6);
                break;
            case 3: // down se aa skte
                can_receive_here = (to_type == 2 || to_type == 3 || to_type == 4);
                break;
        }

        return can_go_from_here && can_receive_here;
    }
    
    bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}}; // R, L, D, U
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m-1 && y == n-1) return true;

            int curr_type = grid[x][y];
            int dir_idx = 0;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    int next_type = grid[nx][ny];
                    if (can_connect(curr_type, next_type, dir_idx)) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                dir_idx++;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return bfs(grid, visited, m, n);
    }
};
