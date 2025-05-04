// class Solution {
// public:
//     int solveRE(int K, int N) {
//         if (N <= 1)
//             return N; // If 0 or 1 floor, we need at most N drops
//         if (K == 1)
//             return N; // With one egg, we drop from every floor

//         int ans = INT_MAX;

//         for (int i = 1; i <= N; i++) {
//             int broken = solveRE(K - 1, i - 1); // Egg breaks -> Check below
//             int unbroken = solveRE(K, N - i);   // Egg survives -> Check above
//             int worst = 1 + max(broken, unbroken); // Worst-case scenario

//             ans = min(ans, worst);
//         }
//         return ans;
//     }

//     int solveME(vector<vector<int>>& dp, int K, int N) {
//         if (N <= 1)
//             return N;
//         if (K == 1)
//             return N;

//         if (dp[K][N] != -1)
//             return dp[K][N];

//         int ans = INT_MAX;

//         for (int i = 1; i <= N; i++) {
//             int broken = solveME(dp, K - 1, i - 1);
//             int unbroken = solveME(dp, K, N - i);
//             int worst = 1 + max(broken, unbroken); // ek move to le liya ab chahe toota ho ya na toota ho egg

//             ans = min(ans, worst);
//         }

//         return dp[K][N] = ans;
//     }

//     int solve_Binary_ME(vector<vector<int>>& dp, int K, int N) {
//         if (N <= 1)
//             return N;
//         if (K == 1)
//             return N;

//         if (dp[K][N] != -1)
//             return dp[K][N];

//         int ans = INT_MAX;
//         int l = 1, r = N;

//         while (l <= r) {
//             int mid = (l + r) >> 1;

//             int broken =
//                 solve_Binary_ME(dp, K - 1, mid - 1); // Egg breaks → check below
//             int unbroken =
//                 solve_Binary_ME(dp, K, N - mid); // Egg survives → check above

//             int worst = 1 + max(broken, unbroken);
//             ans = min(ans, worst);

//             if (broken > unbroken) {
//                 r = mid - 1; // Move downwards
//             } else {
//                 l = mid + 1; // Move upwards
//             }
//         }

//         return dp[K][N] = ans;
//     }
    
//     int twoEggDrop(int n) {
//         vector<vector<int>> dp(3, vector<int>(n + 1, -1));

//         return solve_Binary_ME(dp, 2, n);
//     }
// };


class Solution {
public:
    int twoEggDrop(int n) {
        return ceil(ceil(-1 + sqrt(1 + 8 * n)) / 2.0);
}
};