class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n, 0), right_sum(n, 0), ans(n);
        // Left prefix sum
        for (int i = 1; i < n; i++)
            left_sum[i] = left_sum[i - 1] + nums[i - 1];
        // Right prefix sum
        for (int i = n - 2; i >= 0; i--)
            right_sum[i] = right_sum[i + 1] + nums[i + 1];
        // Calculate the answer
        for (int i = 0; i < n; ++i)
            ans[i] = abs(left_sum[i] - right_sum[i]);

        return ans;
    }
};
