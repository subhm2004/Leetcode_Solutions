class Solution {
public:
    int solveRE(int i, int j, vector<vector<int>>& arr) {
        if (i == arr.size() - 1) {
            return arr[i][j]; // Base case: last row
        }

        int down = solveRE(i + 1, j, arr);
        int diagonal = solveRE(i + 1, j + 1, arr);

        return arr[i][j] + min(down, diagonal);
    }

    int solveME(int i, int j, vector<vector<int>>& arr,
                vector<vector<int>>& dp) {
        if (i == arr.size() - 1) {
            return arr[i][j]; // Base case: last row
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return precomputed result
        }

        int down = solveME(i + 1, j, arr, dp);
        int diagonal = solveME(i + 1, j + 1, arr, dp);

        return dp[i][j] = arr[i][j] + min(down, diagonal);
    }
    int solve_bottom_up(vector<vector<int>>& arr) {
        int n = arr.size(); // arr ka size (rows ki count)
        vector<int> dp(n);  // 1D array banaya size n ka

        /*
        STEP 1: BASE CASE INITIALIZATION
        - Last row (n-1) ke saare elements copy karo dp mein
        - Kyunki last row se neeche koi path nahi hai
        - Direct values return karni hai
        */
        for (int j = 0; j < n; j++) {
            dp[j] = arr[n - 1][j]; // Last row copy
        }

        /*
        STEP 2: BOTTOM-UP PROCESSING
        - Second last row (n-2) se start karo
        - Upar ki taraf move karo (i-- means upward)
        */
        for (int i = n - 2; i >= 0; i--) {
            /*
            Current row i process kar rahe hain
            Har position j ke liye optimal path calculate karo
            */
            for (int j = 0; j <= i; j++) { // j <= i kyunki arr shape
                /*
                KEY INSIGHT:
                - dp[j] = previous iteration mein row (i+1), position j ka
                result
                - dp[j+1] = previous iteration mein row (i+1), position (j+1) ka
                result

                Current position (i,j) se neeche jane ke 2 options:
                1. (i+1, j) - straight down
                2. (i+1, j+1) - diagonal down
                */
                dp[j] = arr[i][j] + min(dp[j], dp[j + 1]);
                /*
                arr[i][j] = current cell ka value
                min(dp[j], dp[j+1]) = minimum path from next row
                */
            }
        }

        return dp[0]; // Top element mein final answer stored hai
    }

    /*
    EXAMPLE WALKTHROUGH:
    arr:
    [2]     <- i=0
    [3,4]    <- i=1
    [6,5,7]   <- i=2
    [4,1,8,3]  <- i=3 (last row)

    EXECUTION:
    1. n = 4
    2. dp = [0,0,0,0] (initially)

    3. Base case initialization (i=3):
    dp = [4,1,8,3]  // Copy last row

    4. i=2 (row [6,5,7]):
    j=0: dp[0] = 6 + min(dp[0], dp[1]) = 6 + min(4,1) = 6+1 = 7
    j=1: dp[1] = 5 + min(dp[1], dp[2]) = 5 + min(1,8) = 5+1 = 6
    j=2: dp[2] = 7 + min(dp[2], dp[3]) = 7 + min(8,3) = 7+3 = 10
    dp = [7,6,10,3]

    5. i=1 (row [3,4]):
    j=0: dp[0] = 3 + min(dp[0], dp[1]) = 3 + min(7,6) = 3+6 = 9
    j=1: dp[1] = 4 + min(dp[1], dp[2]) = 4 + min(6,10) = 4+6 = 10
    dp = [9,10,10,3]

    6. i=0 (row [2]):
    j=0: dp[0] = 2 + min(dp[0], dp[1]) = 2 + min(9,10) = 2+9 = 11
    dp = [11,10,10,3]

    7. Return dp[0] = 11 (minimum path sum)
    */
    int solveME_top_down(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = arr[0][0]; // start from top

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    dp[i][j] = arr[i][j] + dp[i - 1][j]; // left edge
                else if (j == i)
                    dp[i][j] = arr[i][j] + dp[i - 1][j - 1]; // right edge
                else
                    dp[i][j] = arr[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    int minimumTotal(vector<vector<int>>& arr) {
        // return solveRE(0, 0, arr);
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        // return solveME(0, 0, arr, dp);
        return solve_bottom_up(arr);
        // return solveME_top_down(arr);
    }
};
