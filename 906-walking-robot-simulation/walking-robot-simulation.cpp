class Solution {
public:
    bool isObstacle(vector<vector<int>>& obstacles, int x, int y) {
        for (auto& o : obstacles) {
            if (o[0] == x && o[1] == y) {
                return true;
            }
        }
        return false;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // North, East, South, West
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int d_idx = 0; // initially North

        int x = 0, y = 0;
        int ans = 0;

        for (int cmd : commands) {

            if (cmd == -1) {
                // Right turn
                d_idx = (d_idx + 1) % 4;
            }
            else if (cmd == -2) {
                // Left turn
                d_idx = (d_idx + 3) % 4;
            }
            else {
                int dx = directions[d_idx].first;
                int dy = directions[d_idx].second;

                for (int step = 0; step < cmd; step++) {
                    // next positon ye hogi 
                    int nx = x + dx;
                    int ny = y + dy;

                    // agar obstacle hai next position pr toh ruk jao
                    if (isObstacle(obstacles, nx, ny)) break;
                    
                    // ab robot ki position ye hai
                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};