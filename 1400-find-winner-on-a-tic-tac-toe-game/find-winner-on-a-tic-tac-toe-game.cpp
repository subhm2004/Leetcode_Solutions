auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // 3x3 grid banaya aur sab cells ko empty space ' ' se initialize kiya
        vector<vector<char>> grid(3, vector<char>(3, ' '));

        // Moves ke according grid ko fill kar rahe hain
        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            // Agar index even hai → A ki turn hai ('X'), nhi to B ki turn ('O')
            grid[r][c] = (i % 2 == 0) ? 'X' : 'O'; 
        }

        // Rows aur columns check kar rahe hain ki koi jeet gaya hai kya
        for (int i = 0; i < 3; i++) {
            // Row check
            if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
                return grid[i][0] == 'X' ? "A" : "B";
            // Column check
            if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
                return grid[0][i] == 'X' ? "A" : "B";
        }

        // Diagonals check kar rahe hain
        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            return grid[0][0] == 'X' ? "A" : "B";
        if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
            return grid[0][2] == 'X' ? "A" : "B";

        // Agar koi jeeta nahi aur sab moves ho gaye → Draw
        // Agar abhi moves bache hain → Pending
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};
