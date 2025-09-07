class Solution {
public:
    int solveRE(int k, int n) {
        if (k == 1)
            return n;
        if (n <= 1)
            return n;
        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int broken = solveRE(k - 1, i - 1);
            int unbroken = solveRE(k, n - i);

            int worst = 1 + max(broken, unbroken);

            ans = min(ans, worst);
        }
        return ans;
    }

    int solveME(int k, int n, vector<vector<int>>& dp) {
        if (k == 1)
            return n;
        if (n <= 1)
            return n;
        if (dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int broken = solveME(k - 1, i - 1, dp);
            int unbroken = solveME(k, n - i, dp);

            int worst = 1 + max(broken, unbroken);

            ans = min(ans, worst);
        }
        return dp[k][n] = ans;
    }

    int solve_Binary_ME(int k, int n, vector<vector<int>>& dp) {
        if (k == 1)
            return n;
        if (n <= 1)
            return n;
        if (dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int broken = solve_Binary_ME(k - 1, mid - 1, dp);

            int unbroken = solve_Binary_ME(k, n - mid, dp);

            int worst = 1 + max(broken, unbroken);

            ans = min(ans, worst);

            if (broken > unbroken) {
                r = mid - 1;

            } else {
                l = mid + 1;
            }
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        // return solveRE(k, n);
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        // return solveME(k, n, dp);
        return solve_Binary_ME(k, n, dp);
    }
};