class Solution {
public:
    int solveME(vector<int>& nums, int i, vector<int>& dp) {
        if (i < 0)
            return 0;
        if (i == 0) {
            return nums[0];
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // include
        int include = solveME(nums, i - 2, dp) + nums[i];
        int exclude = solveME(nums, i - 1, dp) + 0;

        return dp[i] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size() - 1;

        vector<int> dp(n + 1, -1);
        return solveME(nums, n, dp);
    }
};