class Solution {
public:
    vector<int> prefix_sum;
    int K;
    int dp[35][35];
    int sum(int l, int r) { return prefix_sum[r + 1] - prefix_sum[l]; }

    int solve(int i, int j) {
        // base case: 0 or 1 element interval
        if (i >= j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int min_cost = INT_MAX;

        // partition into (K-1) sized jumps
        // n, n-(K-1), n-2*(K-1), ... soo isliye hum ne kiya hai idx += (K - 1)
        for (int idx = i; idx < j; idx += (K - 1)) {
            int cost = solve(i, idx) + solve(idx + 1, j);
            min_cost = min(min_cost, cost);
        }

        // check if merge possible now
        // only when this interval can collapse to 1 pile
        // int length (n) = j - i + 1
        // merge condition is n - 1) % (K - 1) == 0 sooo (j - i) % (K - 1) == 0
        if ((j - i) % (K - 1) == 0) {
            min_cost += sum(i, j);
        }

        return dp[i][j] = min_cost;;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        K = k;

        // impossible case check
        if ((n - 1) % (K - 1) != 0)
            return -1;

        // prefix sum
        prefix_sum.assign(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix_sum[i + 1] = prefix_sum[i] + stones[i];
        }
        
        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1);
    }
};
