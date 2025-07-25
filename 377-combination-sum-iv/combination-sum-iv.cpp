class Solution {
public:
    int solveRE( vector<int>& nums, int target) {
        if (target == 0)
            return 1;

        int result = 0;
        for (int num : nums) {
            if (target >= num) {
                result += solveRE(nums, target - num);
            }
        }
        return result;
    }
    int solveME( vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];

        int result = 0;
        for (int num : nums) {
            if (target >= num) {
                result += solveME(nums, target - num, dp);
            }
        }
        return dp[target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solveME(nums, target, dp);
        // return solveRE(nums, target);
    }
};
