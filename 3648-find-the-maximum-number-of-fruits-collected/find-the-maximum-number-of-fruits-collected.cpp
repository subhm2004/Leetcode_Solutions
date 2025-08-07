class Solution {
public:

    int n;
    vector<vector<int>> dp2, dp3;   
    // Child 1: Diagonal from top-left to bottom-right
    int child_1_Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;  // Mark as visited
        }
        return ans;
    }

    // Child 2: From (0, n-1) towards diagonal or below
    int child_2_Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (i == j || i > j) return 0;

        if (dp2[i][j] != -1) return dp2[i][j];

        int leftcorner = child_2_Collect(i + 1, j - 1, grid);
        int middle     = child_2_Collect(i + 1, j, grid);
        int rightcorner= child_2_Collect(i + 1, j + 1, grid);

        return dp2[i][j] = grid[i][j] + max({leftcorner, middle, rightcorner});
    }

    // Child 3: From (n-1, 0) towards diagonal or above
    int child_3_Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (i == j || j > i) return 0;

        if (dp3[i][j] != -1) return dp3[i][j];

        int topcorner   = child_3_Collect(i - 1, j + 1, grid);
        int right       = child_3_Collect(i, j + 1, grid);
        int rightcorner = child_3_Collect(i + 1, j + 1, grid);

        return dp3[i][j] = grid[i][j] + max({topcorner, right, rightcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        dp2.assign(n, vector<int>(n, -1));
        dp3.assign(n, vector<int>(n, -1));

        // First child collects diagonal
        int first_child_score = child_1_Collect(grid);

        // Second child from top-right
        int second_child_score = child_2_Collect(0, n - 1, grid);

        // Third child from bottom-left
        int third_child_Score = child_3_Collect(n - 1, 0, grid);

        return first_child_score + second_child_score + third_child_Score;
    }
};
