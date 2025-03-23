class Solution {
public:
    double solveRE(int n, int moves, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0.0;  // Out of bounds
        if (moves == 0)
            return 1.0;  // Valid position, no more moves

        vector<pair<int, int>> dirs = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                       {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        constexpr double kProb = 0.125;  // 1/8 probability per move

        double prob = 0.0;
        for (auto& d : dirs) {
            prob += kProb * solveRE(n, moves - 1, i + d.first, j + d.second);
        }
        return prob;
    }

    double solveME(int n, int moves, int i, int j, vector<vector<vector<double>>>& dp) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0.0;  
        if (moves == 0)
            return 1.0;  

        if (dp[moves][i][j] != -1.0)
            return dp[moves][i][j]; 

        vector<pair<int, int>> dirs = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                       {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        constexpr double kProb = 0.125; 
        double prob = 0.0;
        for (auto& d : dirs) {
            prob += kProb * solveME(n, moves - 1, i + d.first, j + d.second, dp);
        }
        return dp[moves][i][j] = prob;  
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return solveME(n, k, row, column, dp); 
    }
};
