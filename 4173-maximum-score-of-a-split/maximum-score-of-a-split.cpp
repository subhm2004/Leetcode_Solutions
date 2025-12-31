class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        // 1. Prefix sum array
        vector<long long> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        // 2. Suffix minimum array
        vector<long long> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min((long long)nums[i], suffix_min[i + 1]);
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            long long score = prefix_sum[i] - suffix_min[i + 1];
            ans = max(ans, score);
        }

        return ans;
    }
};
