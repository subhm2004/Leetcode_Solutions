class SubrectangleQueries {
private:
    vector<vector<int>> ans;

public:
    // Constructor to initialize the rectangle
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        ans = rectangle;
    }

    // Update all values in the specified subrectangle to newValue
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                ans[i][j] = newValue;
            }
        }
    }

    // Get the current value at (row, col)
    int getValue(int row, int col) {
        return ans[row][col];
    }
};
