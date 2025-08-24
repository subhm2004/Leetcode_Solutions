class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zero_count = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zero_count++;

             while (zero_count > 1) {
                if (nums[left] == 0) zero_count--;
                left++;
            }

            // Window size - 1 (kyunki ek element delete karna compulsory hai)
            ans = max(ans, right - left);
        }
        return ans;
    }
};
