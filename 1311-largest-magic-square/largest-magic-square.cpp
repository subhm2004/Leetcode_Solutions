class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> row(m, vector<int>(n+1,0));
        vector<vector<int>> col(n, vector<int>(m+1,0));

        // build prefix sums for rows and columns
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i][j+1] = row[i][j] + grid[i][j];
                col[j][i+1] = col[j][i] + grid[i][j];
            }
        }

        auto getRow = [&](int r, int c1, int c2){
            return row[r][c2+1] - row[r][c1];
        };

        auto getCol = [&](int c, int r1, int r2){
            return col[c][r2+1] - col[c][r1];
        };

        int maxK = min(m, n);
        for(int k = maxK; k >= 1; k--){
            for(int r = 0; r + k <= m; r++){
                for(int c = 0; c + k <= n; c++){
                    
                    int target = getRow(r, c, c+k-1);
                    bool ok = true;

                    // check rows
                    for(int i=1; i<k && ok; i++){
                        if(getRow(r+i, c, c+k-1) != target) ok = false;
                    }

                    // check columns
                    for(int j=0; j<k && ok; j++){
                        if(getCol(c+j, r, r+k-1) != target) ok = false;
                    }

                    // diagonals
                    if(ok){
                        int d1 = 0, d2 = 0;
                        for(int i=0;i<k;i++){
                            d1 += grid[r+i][c+i];
                            d2 += grid[r+i][c+k-1-i];
                        }
                        if(d1 == target && d2 == target)
                            return k;
                    }
                }
            }
        }
        return 1;
    }
};
