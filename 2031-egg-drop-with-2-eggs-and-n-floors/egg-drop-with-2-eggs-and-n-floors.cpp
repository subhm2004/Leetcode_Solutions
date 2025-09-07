class Solution {
public:
    // int solve_Binary_ME(int k, int n, vector<vector<int>>& dp) {
    //     if (k == 1)
    //         return n;
    //     if (n <= 1)
    //         return n;
    //     if (dp[k][n] != -1)
    //         return dp[k][n];

    //     int ans = INT_MAX;
    //     int l = 1, r = n;
    //     while (l <= r) {
    //         int mid = (l + r) >> 1;
    //         int broken = solve_Binary_ME(k - 1, mid - 1, dp);

    //         int unbroken = solve_Binary_ME(k, n - mid, dp);

    //         int worst = 1 + max(broken, unbroken);

    //         ans = min(ans, worst);

    //         if (broken > unbroken) {
    //             r = mid - 1;

    //         } else {
    //             l = mid + 1;
    //         }
    //     }
    //     return dp[k][n] = ans;
    // }

    int twoEggDrop(int n) {
        // int k = 2 ;
        // vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        // return solve_Binary_ME(k, n, dp);
        return ceil(ceil(-1 + sqrt(1 + 8 * n)) / 2.0);
    }
};
