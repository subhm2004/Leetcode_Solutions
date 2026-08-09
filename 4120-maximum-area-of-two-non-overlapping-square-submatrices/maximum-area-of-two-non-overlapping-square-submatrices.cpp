class PrefixSum2D {
public:
    int n, m;
    vector<vector<int>> prefix;

    PrefixSum2D(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        prefix.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix[i][j] = arr[i][j] + (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
    }

    int getSum(int r1, int c1, int r2, int c2) {
        return prefix[r2][c2] - (r1 > 0 ? prefix[r1 - 1][c2] : 0) -
               (c1 > 0 ? prefix[r2][c1 - 1] : 0) +
               (r1 > 0 && c1 > 0 ? prefix[r1 - 1][c1 - 1] : 0);
    }
};

class Solution {
public:
    bool is_possible(int mid, int m, int n, PrefixSum2D& ps) {
        int min_row = INT_MAX, max_row = INT_MIN;
        int min_col = INT_MAX, max_col = INT_MIN;
        bool found = false;

        for (int r = 0; r + mid <= m; r++) {
            for (int c = 0; c + mid <= n; c++) {

                if (ps.getSum(r, c, r + mid - 1, c + mid - 1) == mid * mid) {
                    found = true;

                    min_row = min(min_row, r);
                    max_row = max(max_row, r);
                    min_col = min(min_col, c);
                    max_col = max(max_col, c);
                }
            }
        }

        if (!found)
            return false;

        return (max_row - min_row >= mid) || (max_col - min_col >= mid);
    }
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        PrefixSum2D ps(mat);

        int low = 1;
        int high = 500;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (is_possible(mid, m, n, ps)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return ans * ans;
    }
};