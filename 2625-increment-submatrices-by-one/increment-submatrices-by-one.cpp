class Solution {
public:
    int val = 1;
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for (int i = r1; i <= r2; i++) {
                diff[i][c1] += val;
                if (c2 + 1 < n) diff[i][c2 + 1] -= val;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        return diff;
    }
};
