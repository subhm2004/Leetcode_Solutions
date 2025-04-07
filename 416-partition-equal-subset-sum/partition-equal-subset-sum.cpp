class Solution {
public:
    bool solveRE(int i, vector<int>& nums, int target) {
        // Agar index array ke size se bahar chala gaya ya target negative ho
        // gaya
        if (i >= nums.size() || target < 0)
            return false;

        // Agar target 0 ho gaya to iska matlab solution mil gaya
        if (target == 0)
            return true;

        // Current element ko include kar ke recursion call kar rahe hain
        bool include = solveRE(i + 1, nums, target - nums[i]);

        // Current element ko exclude kar ke recursion call kar rahe hain
        bool exclude = solveRE(i + 1, nums, target);

        // Agar kisi bhi case me true mila to return true
        return include || exclude;
    }

    bool solveME(int i, vector<int>& nums, int target,
                 vector<vector<int>>& dp) {
        if (i >= nums.size() || target < 0)
            return false;
        if (target == 0)
            return true;
        if (dp[i][target] != -1)
            return dp[i][target];

        bool include = solveME(i + 1, nums, target - nums[i], dp);
        bool exclude = solveME(i + 1, nums, target, dp);

        return dp[i][target] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        // sum calculate karte hai 
        // int sum = accumulate(nums.begin(), nums.end(), 0); 
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum & 1)
            return false;

        int target = sum / 2;
        int n = nums.size();

        // return solveRE(0, nums, target);

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveME(0, nums, target, dp);
    }
};
