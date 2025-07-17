class Solution {
public:
    int solveRE(int i, int prev_rem, int target_rem, int k, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int include = 0;
        int curr_rem = nums[i] % k;

        // Include nums[i] agar ye phle hai OR remainder condition ko satisfy karta hai 
        if (prev_rem == -1 || (prev_rem + curr_rem) % k == target_rem) {
            include = 1 + solveRE(i + 1, curr_rem, target_rem, k, nums);
        }

        // Exclude nums[i]
        int exclude = solveRE(i + 1, prev_rem, target_rem, k, nums);

        return max(include, exclude);
    }

    
     int solveME(int i, int prev_rem, int target_rem, int k, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        if (k == 1) return nums.size();


        // prev_rem: -1 (no previous) to k-1 → shift by +1 for indexing
        if (dp[i][prev_rem + 1] != -1) return dp[i][prev_rem + 1];

        int include = 0;
        int curr_rem = nums[i] % k;

        if (prev_rem == -1 || (prev_rem + curr_rem) % k == target_rem) {
            include = 1 + solveME(i + 1, curr_rem, target_rem, k, nums, dp);
        }

        int exclude = solveME(i + 1, prev_rem, target_rem, k, nums, dp);

        return dp[i][prev_rem + 1] = max(include, exclude);
    }

 
    int solve_bottom_up(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        
        // Try all possible target remainders (0 to k-1)
        for (int target_rem = 0; target_rem < k; target_rem++) {
            // dp[i] = maximum length of valid subsequence ending at index i
            // for current target remainder
            vector<int> dp(n, 1); // har element khud mein ek subsequence hai
            
            // LIS jaisa approach - har i ke liye pichle sare j check karo
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    // Check if we can extend subsequence ending at j with element at i
                    int prev_rem = nums[j] % k;
                    int curr_rem = nums[i] % k;
                    
                    if ((prev_rem + curr_rem) % k == target_rem) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                max_len = max(max_len, dp[i]);
            }
            
            // Early termination optimization
            if (max_len == n) break;
        }
        
        return max_len;
    }

    int solve_bottom_up_optmized(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        
        // For k = 1, all numbers have remainder 0, so answer is n
        if (k == 1) return n;
        
        for (int target_rem = 0; target_rem < k; target_rem++) {
            vector<int> dp(k, 0);
            
            for (int num : nums) {
                int curr_rem = num % k;
                
                // Calculate what previous remainder we need
                int needed_prev = (target_rem - curr_rem + k) % k;
                
                int new_len = 1; // Single element subsequence
                
                // If we can extend from the needed previous remainder
                if (dp[needed_prev] > 0) {
                    new_len = max(new_len, dp[needed_prev] + 1);
                }
                
                dp[curr_rem] = max(dp[curr_rem], new_len);
                max_len = max(max_len, dp[curr_rem]);
            }
            
            if (max_len == n) break;
        }
        
        return max_len;
    }

    int maximumLength(vector<int>& nums, int k) {
        int max_len = 0;
        int n = nums.size();


        // 0 se k-1 tak ke sare number ko target remainder leke solve kar do 

        // for (int target_rem = 0; target_rem < k; target_rem++) {
        //     int ans = solveRE(0, -1, target_rem, k, nums);
        //     max_len = max(max_len, ans);
        // }

        // for (int target_rem = 0; target_rem < k; target_rem++) {
        //     // har ek call ke liye obviously alag dp state table banegi to bana di 
        //     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        //     int ans = solveME(0, -1, target_rem, k, nums, dp);
        //     max_len = max(max_len, ans);
        //     if (max_len == n) break;
        // }

       return solve_bottom_up_optmized(nums,k);

 
    

        // return max_len;
    }
};
