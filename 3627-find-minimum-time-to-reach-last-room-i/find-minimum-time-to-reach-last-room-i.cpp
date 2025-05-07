using T = tuple<int, int, int>; // {time, row, col}

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<T, vector<T>, greater<>> pq;
        minTime[0][0] = 0;
        pq.emplace(0, 0, 0); // {time, row, col}

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!pq.empty()) {
            auto [currTime, i, j] = pq.top();
            pq.pop();

            if (visited[i][j])
                continue;
            visited[i][j] = true;

            if (i == n - 1 && j == m - 1)
                return currTime;

            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    int waitTime = max(A[x][y], currTime) + 1;
                    if (minTime[x][y] > waitTime) {
                        minTime[x][y] = waitTime;
                        pq.emplace(waitTime, x, y);
                    }
                }
            }
        }
        return -1;
    }
};
