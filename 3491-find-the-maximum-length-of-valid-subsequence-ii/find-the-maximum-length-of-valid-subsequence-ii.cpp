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
        
        // Special case: k=1 me saare numbers ka remainder 0 hota hai
        // Isliye saare elements ko le sakte hain, answer = n
        if (k == 1) return n;
        
        // Har possible target remainder (0 se k-1 tak) try karte hain
        for (int target_rem = 0; target_rem < k; target_rem++) {
            
            // dp[rem] = maximum length of subsequence ending with remainder 'rem'
            // Matlab dp[i] me store hai ki remainder i ke saath ending subsequence ki max length kya hai
            vector<int> dp(k, 0);
            
            // Har element ko process karte hain
            for (int num : nums) {
                // Current number ka remainder nikaalte hain
                int curr_rem = num % k;
                
                // MAGIC FORMULA: Humein pata karna hai ki previous element ka remainder kya hona chahiye
                // Taaki prev_rem + curr_rem = target_rem (mod k)
                // Mathematical calculation: prev_rem = (target_rem - curr_rem + k) % k
                // +k isliye add kiya kyunki negative values handle karne ke liye
                int needed_prev = (target_rem - curr_rem + k) % k;
                
                // Minimum length 1 hai (single element subsequence)
                int new_len = 1;
                
                // Check karte hain ki kya needed_prev remainder ke saath koi subsequence exist karta hai
                // Agar dp[needed_prev] > 0 hai matlab koi subsequence hai jo needed_prev remainder ke saath end hota hai
                if (dp[needed_prev] > 0) {
                    // Existing subsequence ko extend kar sakte hain
                    new_len = max(new_len, dp[needed_prev] + 1);
                }
                
                // dp[curr_rem] ko update karte hain
                // Agar pehle se koi better subsequence curr_rem ke saath ending hai to usse max lenge
                dp[curr_rem] = max(dp[curr_rem], new_len);
                
                // Overall maximum length track karte hain
                max_len = max(max_len, dp[curr_rem]);
            }
            
            // Early termination: Agar max possible length mil gaya (n) to break kar do
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
