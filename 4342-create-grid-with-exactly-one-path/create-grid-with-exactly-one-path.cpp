class Solution {
public:

    // recursion se path bana rahe hain
    void dfs(int i, int j, int m, int n, vector<string>& grid) {

        // current cell ko free kar do
        grid[i][j] = '.';

        // destination aa gaya
        if (i == m - 1 && j == n - 1)
            return;

        // agar right ja sakte hain to right jao
        if (j + 1 < n)
            dfs(i, j + 1, m, n, grid);

        // warna down jao
        else
            dfs(i + 1, j, m, n, grid);
    }

    vector<string> createGrid(int m, int n) {

        // initially sab blocked
        vector<string> grid(m, string(n, '#'));

        // (0,0) se unique path banao
        dfs(0, 0, m, n, grid);

        return grid;
    }
};