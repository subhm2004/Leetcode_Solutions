class Solution {
public:
    int solveRE(int l, int r, int target, vector<int>& nums) {
        if (r - l < 1) return 0; // Base case: If there's no valid pair left, return 0

        int ans = 0;
        if (nums[l] + nums[l + 1] == target) 
            ans = max(ans, 1 + solveRE(l + 2, r, target, nums));
        
        if (nums[l] + nums[r] == target) 
            ans = max(ans, 1 + solveRE(l + 1, r - 1, target, nums));
        
        if (nums[r - 1] + nums[r] == target) 
            ans = max(ans, 1 + solveRE(l, r - 2, target, nums));

        return ans;
    }

    int solveME(int l, int r, int target, vector<vector<int>>& dp, vector<int>& nums) {
        if (r - l < 1) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        if (nums[l] + nums[l + 1] == target) 
            ans = max(ans, 1 + solveME(l + 2, r, target, dp, nums));
        
        if (nums[l] + nums[r] == target) 
            ans = max(ans, 1 + solveME(l + 1, r - 1, target, dp, nums));
        
        if (nums[r - 1] + nums[r] == target) 
            ans = max(ans, 1 + solveME(l, r - 2, target, dp, nums));

        return dp[l][r] = ans;
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Using memoized approach
        int a = solveME(2, n - 1, nums[0] + nums[1], dp, nums);
        int b = solveME(0, n - 3, nums[n - 2] + nums[n - 1], dp, nums);
        int c = solveME(1, n - 2, nums[0] + nums[n - 1], dp, nums);

        return 1 + max({a, b, c});
    }
};
