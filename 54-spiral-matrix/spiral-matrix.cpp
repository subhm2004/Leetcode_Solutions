class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        int dir = 0;
        // dir
        // 0   -> left  to right
        // 1   -> top   to down
        // 2   -> right to left
        // 3   -> down  to top

        while (result.size() != m * n) {
            // left to right
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            // top to down
            if (dir == 1) {
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            // right to left
            if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            // down to top
            if (dir == 3) {
                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;
            if (dir == 4)
                dir = 0;
        }
        return result;
    }
};