class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int totalSum = accumulate(colsum.begin(), colsum.end(), 0);
        int twosCount = count(colsum.begin(), colsum.end(), 2);

        // Check if it's possible to split the sum into two rows
        if (upper + lower != totalSum || min(upper, lower) < twosCount)
            return {};

        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));

        // Place '2's first (both rows must have 1)
        for (int j = 0; j < n; j++) {
            if (colsum[j] == 2) {
                ans[0][j] = ans[1][j] = 1;
                upper--;
                lower--;
            }
        }

        // Place '1's in the remaining spots
        for (int j = 0; j < n; j++) {
            if (colsum[j] == 1) {
                if (upper > 0) {
                    ans[0][j] = 1;
                    upper--;
                } else {
                    ans[1][j] = 1;
                    lower--;
                }
            }
        }

        return ans;
    }
};
