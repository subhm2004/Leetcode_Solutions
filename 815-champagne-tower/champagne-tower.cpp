class Solution {
public:
    double dp[101][101];

    double solve(int poured, int row, int glass) {
        if (glass < 0 || glass > row)
            return 0.0;

        if (row == 0 && glass == 0)
            return poured;

        if (dp[row][glass] != -1.0)
            return dp[row][glass];

        double left = solve(poured, row - 1, glass - 1);
        double right = solve(poured, row - 1, glass);

        double from_left = max(0.0, left - 1.0) / 2.0;
        double from_right = max(0.0, right - 1.0) / 2.0;

        return dp[row][glass] = from_left + from_right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                dp[i][j] = -1.0;
            }
        }
        return min(1.0, solve(poured, query_row, query_glass));
    }
};
