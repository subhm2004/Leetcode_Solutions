class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;

    int solve(int i, int target) {

        // target mil gya hai 
        if (target == 0)
            return 0;

        // array khtam ho gya lekin target abhi bhi bacha hai 
        if (i == nums.size() && target > 0)
            return -1e9;

        if (dp[i][target] != -1)
            return dp[i][target];

        int skip = solve(i + 1, target);

        int take = -1e9;

        if (nums[i] <= target) {
            take = 1 + solve(i + 1, target - nums[i]);
        }

        return dp[i][target] = max(take, skip);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        this->nums = nums;

        int n = nums.size();

        dp.assign(n + 1, vector<int>(target + 1, -1));

        int ans = solve(0, target);

        return ans < 0 ? -1 : ans;
    }
};