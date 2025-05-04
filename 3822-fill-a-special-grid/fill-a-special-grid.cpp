class Solution {
public:
    int value = 0; // value 0 se satart hogi

    void solveRE(vector<vector<int>>& matrix, int row_Start, int rowEnd,
                 int col_Start, int colEnd) {
        int size = rowEnd - row_Start; // Current matrix ka size

        // Base case: Agar 1x1 block bacha hai toh value fill kar do
        if (size == 1) {
            matrix[row_Start][col_Start] = value++; // Current cell ko fill karo aur value ko increment kar do
                                                
            return;
        }

        // Midpoints calculate kar rahe hain
        int mid_Row = row_Start + size / 2; // Current matrix ka middle row
        int mid_Col = col_Start + size / 2; // Current matrix ka middle column

        // Recursively har quadrant ko fill karte hain:

        //  (Top-Right)
        solveRE(matrix, row_Start, mid_Row, mid_Col, colEnd);

        //  (Bottom-Right)
        solveRE(matrix, mid_Row, rowEnd, mid_Col, colEnd);

        //  (Bottom-Left)
        solveRE(matrix, mid_Row, rowEnd, col_Start, mid_Col);

        // (Top-Left)
        solveRE(matrix, row_Start, mid_Row, col_Start, mid_Col);
    }
    vector<vector<int>> specialGrid(int N) {
        vector<vector<int>> matrix(1 << N, vector<int>(1 << N));

        solveRE(matrix, 0, 1 << N, 0, 1 << N);
        return matrix;
    }
};
