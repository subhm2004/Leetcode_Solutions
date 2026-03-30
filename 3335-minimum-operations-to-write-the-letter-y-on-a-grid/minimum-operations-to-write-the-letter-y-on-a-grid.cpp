class Solution {
public:
    int solve(vector<vector<int>>& grid, int y, int notY) {
        int n = grid.size();
        int mid = n / 2;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                bool isY = false;

                if (i <= mid && (i == j || i + j == n - 1))
                    isY = true;

                if (i >= mid && j == mid)
                    isY = true;

                if (isY) {
                    if (grid[i][j] != y)
                        ans++;
                } else {
                    if (grid[i][j] != notY)
                        ans++;
                }
            }
        }

        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans = INT_MAX;

        for (int y = 0; y < 3; y++) {
            for (int notY = 0; notY < 3; notY++) {
                if (y == notY)
                    continue;
                ans = min(ans, solve(grid, y, notY));
            }
        }

        return ans;
    }
};