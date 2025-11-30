class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> remainder_idx; // remainder -> last index
        
        int total_remainder = 0; // poore array ka sum ka remainder
        
        // Step 1: Poore array ka total remainder nikaal rahe hain
        for (int num : nums) {
            total_remainder = (total_remainder + num) % p;
        }
        
        // Step 2: Agar total remainder 0 hai, matlab poora array p se divisible hai
        if (total_remainder == 0) {
            return 0;
        }
        
        remainder_idx[0] = -1; // Shuru me remainder 0 ke liye index -1 set kar rahe hain
        
        int ans = INT_MAX; // Answer ko initially maximum length set kar rahe hain
        int current_remainder = 0; // ab tak ka prefix sum remainder
        
        // Step 3: Traverse karte hain array ko
        for (int i = 0; i < n; i++) {
            // Current prefix sum remainder update karte hain
            current_remainder = (current_remainder + nums[i]) % p;
            
            // Required remainder calculate karte hain
            int required = (current_remainder - total_remainder + p) % p;
            
            // Check karte hain ki required remainder kab mila tha
            if (remainder_idx.find(required) != remainder_idx.end()) {
                // Agar mila, to minimum length update karte hain
                ans = min(ans, i - remainder_idx[required]);
            }
            
            // Current remainder ka last index update karte hain
            remainder_idx[current_remainder] = i;
        }
        
        // Step 4: Final answer return karte hain
        return ans == n ? -1 : ans;
    }
};
