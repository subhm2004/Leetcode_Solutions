class Solution {
public:
    const int MOD = 1e9 + 7;  

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int ans = 1;  
        int prevoious_pos_of_1 = -1;  // Track previous position of '1'
        int count_0 = 0;  // Count zeros between '1's

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {   
                if (prevoious_pos_of_1 != -1) {  
                    count_0 = i - prevoious_pos_of_1 - 1;  // Count zeros between '1's

                    // Har gap ke liye (zeros ka count + 1) possible subarrays hain
                    ans = (1LL * ans * (count_0 + 1)) % MOD;  // Update answer for each gap
                }
                prevoious_pos_of_1 = i;
            }
        }

        // If no '1' found, return 0
        if (prevoious_pos_of_1 == -1) return 0;
        
        return ans;  
    }
};
