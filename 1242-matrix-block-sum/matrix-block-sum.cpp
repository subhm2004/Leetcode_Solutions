class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();     // rows
        int n = mat[0].size();  // cols

        // Step 1: 1-indexed array banate hain (arr[1..m][1..n])
        vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = mat[i - 1][j - 1]; // shift by +1
            }
        }

        // Step 2: Prefix sum build karte hain
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = arr[i][j]
                              + prefix[i - 1][j]
                              + prefix[i][j - 1]
                              - prefix[i - 1][j - 1];
            }
        }

        // Step 3: Har cell ke liye block sum calculate karte hain
        vector<vector<int>> result(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // block boundaries (1-indexed)
                int a = max(1, i - k);
                int b = max(1, j - k);
                int c = min(m, i + k);
                int d = min(n, j + k);

                result[i][j] = prefix[c][d]
                             - prefix[a - 1][d]
                             - prefix[c][b - 1]
                             + prefix[a - 1][b - 1];
            }
        }

        // Step 4: Final output ko 0-indexed bana ke return karte hain
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ans[i - 1][j - 1] = result[i][j];
            }
        }
        return ans;
    }
};
