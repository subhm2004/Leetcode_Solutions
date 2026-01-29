class Solution {
public:
    int rows, cols;
    vector<vector<int>> arr;

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool is_possible(int max_effort) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == rows - 1 && y == cols - 1)
                return true;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                    !visited[nx][ny]) {
                        
                    int diff = abs(arr[x][y] - arr[nx][ny]);

                    if (diff <= max_effort) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        this->arr = heights;
        rows = arr.size();
        cols = arr[0].size();

        int low = 0;
        int high = 1e6;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (is_possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};