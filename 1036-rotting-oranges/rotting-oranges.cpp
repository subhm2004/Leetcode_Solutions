class Solution {
public:
    // Ye function BFS karta hai rotten oranges se aur return karta hai total time (minutes)
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q,
            int& count_fresh) {
        int count = 0;

        // 4 directions mein movement: up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size();
        int cols = grid[0].size();

        // BFS start karo jab tak queue empty na ho jaye
        while (!q.empty()) {
            ++count;  // Har level (minute) ke liye count badhao
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();  // Current rotten orange
                q.pop();

                // 4 directions check karo
                for (auto [dx, dy] : dirs) {
                    int newX = x + dx, newY = y + dy;

                    // Agar naya cell out of bounds ho ya empty (0) ho ya already rotten (2) ho toh skip karo
                    if (newX < 0 || newY < 0 || newX >= rows || newY >= cols ||
                        grid[newX][newY] == 0 || grid[newX][newY] == 2) {
                        continue;
                    }

                    // Fresh orange ko rotten bana do
                    grid[newX][newY] = 2;
                    q.push({newX, newY});  // Ab ye bhi rot karega
                    count_fresh--;         // Fresh orange count kam karo
                }
            }
        }

        // Agar sab fresh oranges rotten ho gaye toh return karo time (count - 1)
        // Nahi toh -1 (matlab impossible tha sabko rotten banana)
        return count_fresh == 0 ? count - 1 : -1;
    }

    // Main function jo grid input ke base par kaam karta hai
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;  // Agar grid hi empty ho toh kuch karne ka matlab nahi

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int count_fresh = 0;  // Fresh oranges ka count

        // Grid mein har cell check karo:
        // Rotten orange ho toh queue mein daalo
        // Fresh orange ho toh count badhao
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    count_fresh++;
                }
            }
        }

        // Agar fresh orange hai hi nahi toh return 0 (sab already rotten ya empty the)
        if (count_fresh == 0)
            return 0;

        // BFS chalao aur return karo minimum time jitna lagta hai sabko rotten banane mein
        return bfs(grid, q, count_fresh);
    }
};
