class Solution {
public:
    // Step 1: Rotate the matrixrix by 90 degrees clockwise
    void rotate_90(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //  Transpose: Flip across diagonal
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //  Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        // Step 3: Try all 4 rotations

        for (int i = 0; i < 4; i++) {
            if (matrix == target) return true;
            rotate_90(matrix);
        }
        return false;
    }
};
