class Solution {
public:
    // Function jo left se LIS calculate karta hai
    int lisFromLeft(const vector<int>& nums, int i, vector<int>& dp) {
        // Agar dp[i] already calculated hai, toh usse return karo
        if (dp[i] != -1) return dp[i];
        
        int maxLength = 1;  // Minimum length 1 hai, kyunki current element khud bhi count hota hai
        for (int j = 0; j < i; ++j) {
            // Agar nums[j] current element se chhota hai, toh LIS ko update karo
            if (nums[j] < nums[i]) 
                maxLength = max(maxLength, 1 + lisFromLeft(nums, j, dp));
        }
        dp[i] = maxLength;  // Result ko cache karo
        return maxLength;  // Maximum length return karo
    }

    // Function jo right se LIS calculate karta hai
    int lisFromRight(const vector<int>& nums, int i, vector<int>& dp) {
        // Agar dp[i] already calculated hai, toh usse return karo
        if (dp[i] != -1) return dp[i];
        
        int maxLength = 1;  // Minimum length 1 hai
        for (int j = i + 1; j < nums.size(); ++j) {
            // Agar nums[j] current element se chhota hai, toh LIS ko update karo
            if (nums[j] < nums[i]) 
                maxLength = max(maxLength, 1 + lisFromRight(nums, j, dp));
        }
        dp[i] = maxLength;  // Result ko cache karo
        return maxLength;  // Maximum length return karo
    }

    // Function jo minimum elements ko remove karne ka count return karta hai
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftLIS(n, -1), rightLIS(n, -1);  // Left aur right LIS ke liye dp arrays

        // Left se LIS calculate karo
        for (int i = 0; i < n; ++i) 
            lisFromLeft(nums, i, leftLIS);

        // Right se LIS calculate karo
        for (int i = n - 1; i >= 0; --i) 
            lisFromRight(nums, i, rightLIS);

        int maxMountainSeq = 0;  // Maximum mountain sequence length
        // Peak ke liye check karo
        for (int i = 1; i < n - 1; ++i) {
            // Agar left aur right LIS dono 1 se zyada hain, toh peak hai
            if (leftLIS[i] > 1 && rightLIS[i] > 1) 
                maxMountainSeq = max(maxMountainSeq, leftLIS[i] + rightLIS[i] - 1);
        }
        return n - maxMountainSeq;  // Total elements se maximum mountain sequence length ko subtract karo
    }
};