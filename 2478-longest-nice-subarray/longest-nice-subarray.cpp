class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 0, usedBits = 0, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (usedBits & nums[right]) { 
                usedBits ^= nums[left]; // Remove nums[left] from usedBits
                left++; 
            }
            usedBits |= nums[right]; // Add nums[right] to usedBits
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
