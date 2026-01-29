// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
//             return -1;

//         queue<tuple<int, int, int>> q; // {row, col, distance}
//         q.push({0, 0, 1});
//         grid[0][0] = 1; // Mark as visited
//         vector<vector<int>> directions{{1, 1},  {0, 1},   {1, 0},  {0, -1},
//                                        {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

//         while (!q.empty()) {
//             auto [x, y, dist] = q.front();
//             q.pop();

//             if (x == m - 1 && y == n - 1)
//                 return dist;

//             for (auto& dir : directions) {
//                 int nx = x + dir[0];
//                 int ny = y + dir[1];

//                 if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
//                     grid[nx][ny] == 0) {
//                     q.push({nx, ny, dist + 1});
//                     grid[nx][ny] = 1; // Mark as visited
//                 }
//             }
//         }
//         return -1;
//     }
// };


// Dijskstra's Algorithm ka use krke using pririty queue

class Solution {
public:
    using T = tuple<int, int, int>; // {row, col, distance}

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 1); 

        vector<vector<int>> directions{{1, 1},  {0, 1},   {1, 0},  {0, -1},
                                       {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); 
        dist[0][0] = 1;

        while (!pq.empty()) {
            auto [x, y, d] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return d;

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        dist[nx][ny] = d + 1;
                        pq.emplace(nx, ny, d + 1); 
                    }
                }
            }
        }
        return -1;
    }
};
