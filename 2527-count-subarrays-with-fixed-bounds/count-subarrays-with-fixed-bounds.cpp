class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMinK = -1, lastMaxK = -1, lastInvalid = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;  // mark the invalid position where a number outside [minK, maxK] is encountered
            }
            
            if (nums[i] == minK) {
                lastMinK = i;  // update the last seen position of minK
            }
            
            if (nums[i] == maxK) {
                lastMaxK = i;  // update the last seen position of maxK
            }
            
            // A valid subarray exists only when both minK and maxK have appeared
            if (lastMinK != -1 && lastMaxK != -1) {
                // Add the number of valid subarrays formed by considering the range
                count += max(0, min(lastMinK, lastMaxK) - lastInvalid);
            }
        }

        return count;
    }
};
