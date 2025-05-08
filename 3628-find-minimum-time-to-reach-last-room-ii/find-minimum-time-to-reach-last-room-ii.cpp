using T = tuple<int, int, int, int>; // {time, row, col, move_Count}

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<vector<int>>> minTime(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
        
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, 0, 0, 0); // {time, row, col, move_Count}
        minTime[0][0][0] = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [currTime, i, j, move_Count] = pq.top();
            pq.pop();
            
            int parity = move_Count % 2;
            if (visited[i][j][parity])
                continue;
                
            visited[i][j][parity] = true;
            
            if (i == n - 1 && j == m - 1)
                return currTime;
                
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int next_Move_Count = move_Count + 1;
                    int next_Parity = next_Move_Count % 2;
                    
                    if (!visited[x][y][next_Parity]) {
                        int move_Cost = (parity == 0) ? 1 : 2;
                    
                        int nextTime = max(currTime, moveTime[x][y]) + move_Cost;
                        
                        if (nextTime < minTime[x][y][next_Parity]) {
                            minTime[x][y][next_Parity] = nextTime;
                            pq.emplace(nextTime, x, y, next_Move_Count);
                        }
                    }
                }
            }
        }
        
        return -1;  
    }
};
