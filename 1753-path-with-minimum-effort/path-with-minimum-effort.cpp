class Solution {
public:
    using T = tuple<int, int, int>; // (effort, x, y)

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0, 0, 0});
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
                    }
                }
            }
        }
        return 0;
    }
};