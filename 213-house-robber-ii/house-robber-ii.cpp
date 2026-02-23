class Solution { // using memo
public:

    int solveME(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (end < start)
            return 0;
        if (start == end)
            return nums[start];
        if (dp[end] != -1)
            return dp[end];

        int include = nums[end] + solveME(nums, start, end - 2, dp);
        int exclude = solveME(nums, start, end - 1, dp);

        return dp[end] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        return max(solveME(nums, 0, n - 2, dp1), solveME(nums, 1, n - 1, dp2));
    }
};
