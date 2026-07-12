class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {

        // Step 1:
        // Sabhi cells ko free ('.') bana dete hain.
        vector<string> grid(m, string(n, '.'));

        // Step 2:
        // First row aur last column ko chhodkar
        // baaki sab cells ko obstacle ('#') bana dete hain.
        //
        // Example (4 x 4):
        //
        // . . . .
        // # # # .
        // # # # .
        // # # # .
        //
        // Is grid me sirf 1 hi valid path hai.
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                grid[i][j] = '#';
            }
        }

        // Agar sirf ek row ya ek column hai,
        // to maximum ek hi path ho sakta hai.
        if (m == 1 || n == 1) {
            if (k == 1)
                return grid;
            return {};
        }

        switch (k) {

            //--------------------------------------------------
            // CASE 1
            //--------------------------------------------------
            case 1:
                // Jo corridor banaya hai wahi answer hai.
                return grid;

            //--------------------------------------------------
            // CASE 2
            //--------------------------------------------------
            case 2:

                // Ek extra cell khol dete hain.
                //
                // Example:
                //
                // . . . .
                // # # . .
                // # # # .
                //
                // Ab exactly 2 paths ban jate hain.
                grid[1][n - 2] = '.';
                break;

            //--------------------------------------------------
            // CASE 3
            //--------------------------------------------------
            case 3:

                // Agar rows aur columns dono 2 se kam hain
                // to 3 paths banana impossible hai.
                if (m < 3 && n < 3)
                    return {};

                // Pehla extra opening
                grid[1][n - 2] = '.';

                // Agar columns kam hain
                // to niche wali cell kholo.
                if (n < 3)
                    grid[2][n - 2] = '.';

                // Warna left wali cell kholo.
                else
                    grid[1][n - 3] = '.';

                break;

            //--------------------------------------------------
            // CASE 4
            //--------------------------------------------------
            case 4:

                // 2x2, 2x3, 3x2 me 4 paths banana possible nahi.
                if (min(m, n) == 2 && max(m, n) < 4)
                    return {};

                // Pehla opening
                grid[1][n - 2] = '.';

                // -------------------------------
                // Horizontal extension possible
                // -------------------------------
                if (m == 2 || n > 3) {

                    grid[1][n - 3] = '.';
                    grid[1][n - 4] = '.';
                }

                // -------------------------------
                // Vertical extension possible
                // -------------------------------
                else if (n == 2 || m > 3) {

                    grid[2][n - 2] = '.';
                    grid[3][n - 2] = '.';
                }

                // -------------------------------
                // Special case : 3 x 3
                // -------------------------------
                else if (m == 3 && n == 3) {

                    // 3x3 ke liye manually arrangement banana padta hai.

                    grid[1][0] = '.';
                    grid[2][1] = '.';

                    // Is obstacle ki wajah se
                    // exactly 4 paths bante hain.
                    grid[0][2] = '#';
                }

                break;
        }

        return grid;
    }
};