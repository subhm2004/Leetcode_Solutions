class Solution {
public:
    void processColumns(vector<vector<char>>& box, vector<vector<char>>& ans,
                        int row, int n, int col, int stonePos) {
        if (col < 0)
            return;
        if (box[row][col] == '*') {
            ans[col][box.size() - row - 1] = '*';
            processColumns(box, ans, row, n, col - 1, col - 1);
        } else if (box[row][col] == '#') {
            ans[stonePos][box.size() - row - 1] = '#';
            processColumns(box, ans, row, n, col - 1, stonePos - 1);
        } else {
            processColumns(box, ans, row, n, col - 1, stonePos);
        }
    }
    void processRows(vector<vector<char>>& box, vector<vector<char>>& ans,
                     int m, int n, int row) {
        if (row < 0)
            return;
        processColumns(box, ans, row, n, n - 1, n - 1);
        processRows(box, ans, m, n, row - 1);
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int m = box.size();
        const int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        processRows(box, ans, m, n, m - 1);
        return ans;
    }
};
