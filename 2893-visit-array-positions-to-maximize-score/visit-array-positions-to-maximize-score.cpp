class Solution {
public:

    long long dp[100005][2];
    vector<int> nums;
    int n, x;

    long long solve(int i, int prev_parity) {

        if (i >= n) return 0;

        if (dp[i][prev_parity] != -1)
            return dp[i][prev_parity];

        // Option 1: skip current index
        long long exclude = solve(i + 1, prev_parity);

        int curr_parity = nums[i] % 2;

        // Option 2: include current index
        long long include;

        if (curr_parity == prev_parity) {
            // no penalty
            include = nums[i] + solve(i + 1, prev_parity);
        } else {
            // parity change → -x
            include = nums[i] + solve(i + 1, curr_parity) - x;
        }

        return dp[i][prev_parity] = max(include, exclude);
    }

    long long maxScore(vector<int>& nums, int x) {

        this-> nums = nums;
        this-> x = x;
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        int prev_parity = nums[0] % 2;

        // index 0 already include hai
        return nums[0] + solve(1, prev_parity);
    }
};