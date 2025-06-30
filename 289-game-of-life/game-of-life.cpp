class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // 8 directions 
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Step 1: sab cells ke liye intermediate state mark karo (jaise 1 se 0 ho raha hai ya 0 se 1)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;

                //  Har neighbour ke liye check karo uska position valid hai ya nahi
                 for (auto [dx, dy] : directions) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        //  Agar neighbour pehle zinda tha ya abhi bhi zinda hai (1 ya 2), to count karo
                        if (board[x][y] == 1 || board[x][y] == 2)
                            live++;
                    }
                }

                //  Rules apply krte h 
                if (board[i][j] == 1) {
                    // Rule 1 or 3: Agar live neighbour < 2 ya > 3 hai → cell dead ho jata hai (2 mark karte hain)
                    if (live < 2 || live > 3)
                        board[i][j] = 2; // live (1) → dead (0)
                } else {
                    // Rule 4: Agar exactly 3 live neighbours hain → dead cell zinda ho jata hai (3 mark karte hain)
                    if (live == 3)
                        board[i][j] = 3; // dead (0) → live (1)
                }
            }
        }

        // Step 2: Final cleanup — intermediate states ko final state me convert karo
        // 2 (live→dead) ko 0 bana do, aur 3 (dead→live) ko 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
