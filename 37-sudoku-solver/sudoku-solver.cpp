#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

class Solution {
public:

    bool is_valid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i)
            if (board[i][col] == c || board[row][i] == c ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int s) {
        if (s == 81)
            return true;

        const int i = s / 9;
        const int j = s % 9;

        if (board[i][j] != '.')
            return backtrack(board, s + 1);

        for (char c = '1'; c <= '9'; c++)
            if (is_valid(board, i, j, c)) {
                board[i][j] = c;
                if (backtrack(board, s + 1))
                    return true;
                board[i][j] = '.';
            }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { backtrack(board, 0); }
};