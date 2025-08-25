class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        int row = 0, col = 0;
        bool up = true; // direction flag

        while (ans.size() < m * n) {
            ans.push_back(arr[row][col]);

            if (up) {
                // move up-right
                if (col == n - 1) { // last column → go down
                    row++;
                    up = false;
                } else if (row == 0) { // first row → go right
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                // move down-left
                if (row == m - 1) { // last row → go right
                    col++;
                    up = true;
                } else if (col == 0) { // first col → go down
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};
