class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Calculate the target (global AND of all elements)
        int target = nums[0];
        for (int x : nums) {
            target &= x;
        }
        
        // Step 2: Check if already all elements are equal to target
        bool al_equal = true;
        for (int x : nums) {
            if (x != target) {
                al_equal = false;
                break;
            }
        }
        if (al_equal) return 0;
        
        // Step 3: Use DP to find minimum operations
        // dp[i] = minimum operations to make nums[0...i-1] all equal to target
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case: empty array needs 0 operations
        
        for (int i = 1; i <= n; i++) {
            // Try all possible subarrays ending at position i-1
            int current_And = nums[i-1];
            for (int j = i-1; j >= 0; j--) {
                if (j < i-1) {
                    current_And &= nums[j];
                }
                
                // If this subarray [j...i-1] can become target
                if (current_And == target && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
                
                // Early termination: if current_And < target, 
                // extending further left won't help
                if (current_And < target) break;
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
