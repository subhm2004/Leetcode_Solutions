class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        for (int x : nums) {
            total_xor ^= x;  
        }

         if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }

         if (total_xor == 0) {
            return nums.size() - 1;
        }
        
         return nums.size();
    }
};