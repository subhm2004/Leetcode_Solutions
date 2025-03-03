class Solution {
public:
    int solveRE(int K, int N) {
        if (N <= 1)
            return N; // If 0 or 1 floor, we need at most N drops
        if (K == 1)
            return N; // With one egg, we drop from every floor

        int res = INT_MAX;

        for (int i = 1; i <= N; i++) {
            int broken = solveRE(K - 1, i - 1); // Egg breaks -> Check below
            int unbroken = solveRE(K, N - i);   // Egg survives -> Check above
            int worst = 1 + max(broken, unbroken); // Worst-case scenario

            res = min(res, worst);
        }
        return res;
    }

    int solveME(vector<vector<int>>& dp, int K, int N) {
        if (N <= 1)
            return N;
        if (K == 1)
            return N;

        if (dp[K][N] != -1)
            return dp[K][N];

        int res = INT_MAX;

        for (int i = 1; i <= N; i++) {
            int broken = solveME(dp, K - 1, i - 1);
            int unbroken = solveME(dp, K, N - i);
            int worst = 1 + max(broken, unbroken);

            res = min(res, worst);
        }

        return dp[K][N] = res;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, -1));

        return solveME(dp, 2, n);
    }
};