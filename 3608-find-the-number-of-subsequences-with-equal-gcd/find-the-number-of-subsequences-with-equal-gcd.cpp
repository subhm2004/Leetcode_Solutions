class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];

    int solve(vector<int>& nums, int i, int seq1_gcd, int seq2_gcd) {
        
        // Base case: array khatam
        if (i == nums.size()) {
            bool both_non_empty = (seq1_gcd != 0 && seq2_gcd != 0);
            bool gcd_matched = (seq1_gcd == seq2_gcd);
            return (both_non_empty && gcd_matched) ? 1 : 0;
        }

        // Already computed? Wahi return kar do
        if (dp[i][seq1_gcd][seq2_gcd] != -1)
            return dp[i][seq1_gcd][seq2_gcd];

        // Skip this index entirely
        int skip = solve(nums, i + 1, seq1_gcd, seq2_gcd);

        // Include this index in seq1
        int include_1 = solve(nums, i + 1, __gcd(seq1_gcd, nums[i]), seq2_gcd);

        // Include this index in seq2
        int include_2 = solve(nums, i + 1, seq1_gcd, __gcd(seq2_gcd, nums[i]));

        return dp[i][seq1_gcd][seq2_gcd] = (0LL + skip + include_1 + include_2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};