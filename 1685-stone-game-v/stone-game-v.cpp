class Solution {
public:
    int n;
    vector<int> stones;
    vector<int> prefix;

    int dp[505][505];   

    int range_sum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r) {
        // base case
        if (l == r) return 0;

        // memoized
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // try krte hai sari split ko
        for (int k = l; k < r; k++) {

            int left_sum  = range_sum(l, k);
            int right_sum = range_sum(k + 1, r);

            if (left_sum < right_sum) {
                ans = max(ans, left_sum + solve(l, k));
            }
            else if (right_sum < left_sum) {
                ans = max(ans, right_sum + solve(k + 1, r));
            }
            else {
                ans = max(ans, left_sum + solve(l, k));
                ans = max(ans, right_sum + solve(k + 1, r));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        stones = stoneValue;
        n = stones.size();

        // prefix sum
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1);
    }
};