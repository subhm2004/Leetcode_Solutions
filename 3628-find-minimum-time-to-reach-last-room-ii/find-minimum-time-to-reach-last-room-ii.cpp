using T = tuple<int, int, int, int>; // {time, row, col, moveCount}

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<vector<int>>> minTime(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
        
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, 0, 0, 0); // {time, row, col, moveCount}
        minTime[0][0][0] = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [currTime, i, j, moveCount] = pq.top();
            pq.pop();
            
            int parity = moveCount % 2;
            if (visited[i][j][parity])
                continue;
                
            visited[i][j][parity] = true;
            
            if (i == n - 1 && j == m - 1)
                return currTime;
                
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int nextMoveCount = moveCount + 1;
                    int nextParity = nextMoveCount % 2;
                    
                    if (!visited[x][y][nextParity]) {
                        int moveCost = (parity == 0) ? 1 : 2;
                    
                        int nextTime = max(currTime, moveTime[x][y]) + moveCost;
                        
                        if (nextTime < minTime[x][y][nextParity]) {
                            minTime[x][y][nextParity] = nextTime;
                            pq.emplace(nextTime, x, y, nextMoveCount);
                        }
                    }
                }
            }
        }
        
        return -1;  
    }
};
