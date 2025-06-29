class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int ans = 0;
        int offset = 500;
        vector<vector<int>> dp(n, vector<int>(1001, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + offset;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff] + 1);
            }
        }

        return ans;
    }
};
