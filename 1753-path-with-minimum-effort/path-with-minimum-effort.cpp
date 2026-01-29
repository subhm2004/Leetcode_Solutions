class Solution { // Dijkstra's Variation
public:
    using T = tuple<int, int, int>; // (effort, x, y)

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0, 0, 0});
    //  pq.emplace(0,0,0);
        effort[0][0] = 0;

        vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!pq.empty()) {
            auto [curr_effor, x, y] = pq.top();
            pq.pop();

            // Agar is cell ke liye already better effort mil chuka ho
            if (curr_effor > effort[x][y]) continue;

            // Destination pr aa gye hai 
            if (x == row - 1 && y == col - 1)
                return curr_effor;

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
                    int new_effort = max(curr_effor, abs(heights[x][y] - heights[nx][ny]));

                    if (new_effort < effort[nx][ny]) {
                        effort[nx][ny] = new_effort;
                        pq.push({new_effort, nx, ny});
                    // pq.emplace(new_effort, nx, ny);
                    }
                }
            }
        }
        return 0;
    }
};

// Binary Search + BFS
// class Solution {
// public:
//     int rows, cols;
//     vector<vector<int>> arr;

//     vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

//     bool is_possible(int max_effort) {
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//         queue<pair<int, int>> q;

//         q.push({0, 0});
//         visited[0][0] = true;

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             if (x == rows - 1 && y == cols - 1)
//                 return true;

//             for (auto [dx, dy] : dirs) {
//                 int nx = x + dx;
//                 int ny = y + dy;

//                 if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
//                     !visited[nx][ny]) {
                        
//                     int diff = abs(arr[x][y] - arr[nx][ny]);

//                     if (diff <= max_effort) {
//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         }
//         return false;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         this->arr = heights;
//         rows = arr.size();
//         cols = arr[0].size();

//         int low = 0;
//         int high = 1e6;
//         int ans = high;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (is_possible(mid)) {
//                 ans = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };