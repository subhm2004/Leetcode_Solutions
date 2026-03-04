class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowSum(m, 0), colSum(n, 0);

        // Step 1: Count 1s in each row and column
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1) {
                    rowSum[i]++;
                    colSum[j]++;
                }

        // Step 2: Find special positions
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1)
                    count++;

        return count;
    }
};
