class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> subgrids(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue; 
                }

                int num = board[i][j] - '1'; 
                int sub_grid_idx = (i / 3) * 3 + (j / 3); // Calculate subgrid index

                if (rows[i][num] || cols[j][num] || subgrids[sub_grid_idx][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                subgrids[sub_grid_idx][num] = true;
            }
        }

        return true; 
    }
};