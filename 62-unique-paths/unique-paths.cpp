class Solution {
public:
    long long nCr(int n, int r) {
        long long ans = 1;

        // Optimization: C(n, r) == C(n, n-r)
        // Agar r > n/2 ho, toh use n-r instead, kyunki C(n,r) = C(n,n-r)
        if (r > n - r)
            r = n - r;

        // Formula: C(n,r) = n*(n-1)*...*(n-r+1) / (1*2*...*r)
        for (int i = 1; i <= r; ++i) {
            ans = ans * (n - i + 1) / i;
        }

        return ans; // Return number of combinations
    }

    int uniquePaths(int m, int n) {
        // Total moves needed = down + right = (m-1) + (n-1) = m+n-2
        // Number of ways to choose down moves (or right moves) = C(total_moves, down_moves)
        return (int)nCr(m + n - 2, m - 1);
        // Equivalent: C(m+n-2, n-1), same result
    }
};

// // Dp solution
// class Solution {
// public:
//     int solveRE(int i, int j, int m, int n) {
//         // Base cases
//         if (i >= m || j >= n) {
//             return 0; // Out of bounds
//         }
//         if (i == m - 1 && j == n - 1) {
//             return 1; // Reached the destination
//         }

//         int right_path = solveRE(i, j + 1, m, n);
//         int down_path = solveRE(i + 1, j, m, n);

//         return right_path + down_path;
//     }

//     int solveME(int i, int j, int m, int n, vector<vector<int>>& dp) {
//         // Base cases
//         if (i >= m || j >= n) {
//             return 0; // Out of bounds
//         }
//         if (i == m - 1 && j == n - 1) {
//             return 1; // Reached the destination
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j]; // Return precomputed ansult
//         }

//         int right_path = solveME(i, j + 1, m, n, dp);
//         int down_path = solveME(i + 1, j, m, n, dp);

//         return dp[i][j] = right_path + down_path;
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solveME(0, 0, m, n, dp);
//     }
// };
