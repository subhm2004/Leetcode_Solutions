class Solution {
public:
    int n, m;
    vector<int> A, B;

    long long dp[101][101][101];

    long long solve(int i, int j, int k) {

        if (k == 0)
            return 0;

        if (i == n || j == m)
            return -4e18;

        if (dp[i][j][k] != LLONG_MIN)
            return dp[i][j][k];

        long long skip_a = solve(i + 1, j, k);
        long long skip_b = solve(i, j + 1, k);

        long long take_both = solve(i + 1, j + 1, k - 1);
        if (take_both != -4e18)
            take_both += 1LL * A[i] * B[j];

        return dp[i][j][k] = max({skip_a, skip_b, take_both});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        A = nums1;
        B = nums2;
        n = A.size();
        m = B.size();

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int t = 0; t <= k; t++)
                    dp[i][j][t] = LLONG_MIN;

        return solve(0, 0, k);
    }
};
