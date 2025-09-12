class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<int>> board(8, vector<int>(8, 0));

        // mark queens on board
        for (auto &q : queens) {
            board[q[0]][q[1]] = 1;
        }

        // 8 directions (dx, dy)
        vector<pair<int,int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},   // up, down, left, right
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // 4 diagonals
        };

        for (auto &dir : directions) {
            int x = king[0], y = king[1];
            while (true) {
                x += dir.first;
                y += dir.second;
                if (x < 0 || x >= 8 || y < 0 || y >= 8) break; // out of board
                if (board[x][y] == 1) { // queen found
                    ans.push_back({x, y});
                    break;
                }
            }
        }

        return ans;
    }
};
