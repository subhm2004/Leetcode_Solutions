class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = INT_MAX;
        
        // Bit count array to track set bits in current window
        vector<int> bitCount(32, 0);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            // Add nums[right] to window
            updateBitCount(bitCount, nums[right], 1);
            
            // Try to shrink window while maintaining OR >= k
            while (left <= right && getORFromBitCount(bitCount) >= k) {
                minLen = min(minLen, right - left + 1);
                // Remove nums[left] from window
                updateBitCount(bitCount, nums[left], -1);
                left++;
            }
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
    
private:
    void updateBitCount(vector<int>& bitCount, int num, int delta) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitCount[i] += delta;
            }
        }
    }
    
    int getORFromBitCount(vector<int>& bitCount) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCount[i] > 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};