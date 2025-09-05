class Solution {
public:

    void update_bit_count(vector<int>& bitCount, int num, int delta) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitCount[i] += delta;
            }
        }
    }
    
    int get_OR_from_bit_count(vector<int>& bitCount) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCount[i] > 0) {
                result |= (1 << i);
            }
        }
        return result;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int min_len = INT_MAX;
        
        // Bit count array to track set bits in current window
        vector<int> bitCount(32, 0);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            // Add nums[right] to window
            update_bit_count(bitCount, nums[right], 1);
            
            // Try to shrink window while maintaining OR >= k
            while (left <= right && get_OR_from_bit_count(bitCount) >= k) {
                min_len = min(min_len, right - left + 1);
                // Remove nums[left] from window
                update_bit_count(bitCount, nums[left], -1);
                left++;
            }
        }
        
        return min_len == INT_MAX ? -1 : min_len;
    }
        
};