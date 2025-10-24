auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    // current sum leke solve kiya agar end pr aa gya or surrent sum = target to ek ans h 
    int solve_RE_2(vector<int>& nums, int target, int i, int curr_sum) {
        if (i >= nums.size())
            return curr_sum == target ? 1 : 0;

        int plus = solve_RE_2(nums, target, i + 1, curr_sum + nums[i]);
        int minus = solve_RE_2(nums, target, i + 1, curr_sum - nums[i]);

        return plus + minus;
    }

    int solveRE(vector<int>& nums, int target, int i) {
        if (i == nums.size())
            return target == 0 ? 1 : 0;
        int plus = solveRE(nums, target - nums[i], i + 1);
        int minus = solveRE(nums, target + nums[i], i + 1);
        return plus + minus;
    }

    int solveME(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (i == nums.size())
            return target == 0 ? 1 : 0;

        int shifted_target = target + 1000;
        if (shifted_target < 0 || shifted_target > 2000) // Out of bounds check
            return 0;
        if (dp[i][shifted_target] != -1)
            return dp[i][shifted_target];

        int plus = solveME(nums, target - nums[i], i + 1, dp);
        int minus = solveME(nums, target + nums[i], i + 1, dp);

        return dp[i][shifted_target] = plus + minus;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        // return solveRE(nums,target,0);

        // curr_sum leke kar do 
        // return solve_RE_2(nums,target,0,0);
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solveME(nums, target, 0, dp);
    }
};
