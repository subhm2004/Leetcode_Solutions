class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int min_Row = m;
        int max_Row = -1;
        int min_Col = n;
        int max_Col = -1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    min_Row = min(min_Row, i);
                    max_Row = max(max_Row, i);

                    min_Col = min(min_Col, j);
                    max_Col = max(max_Col, j);
                }       
            }
        }
        return (max_Row - min_Row + 1) * (max_Col - min_Col + 1);
    }
};