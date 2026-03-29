class PrefixSum2D {
public:
    int n, m;
    vector<vector<int>> prefix; // prefix sum matrix

    PrefixSum2D(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        prefix.assign(n + 1, vector<int>(m + 1, 0));

        // build prefix sum (1-indexed)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = arr[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    // get sum of rectangle (a,b) to (c,d), inclusive
    // NOTE: (a,b) and (c,d) are 1-indexed
    int getSum(int a, int b, int c, int d) {
        return prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] +
               prefix[a - 1][b - 1];
    }
};
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        PrefixSum2D ps(grid);

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = ps.getSum(1, 1, i + 1, j + 1);
                if (sum <= k)
                    count++;
            }
        }

        return count;
    }
};