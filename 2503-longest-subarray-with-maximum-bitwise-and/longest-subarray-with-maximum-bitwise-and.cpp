class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0, count = 0;
        for (int num : nums) {
            if (num == maxi) {
                ++count;
                ans = max(ans, count);
            } else {
                count = 0;
            }
        }
        return ans;
    }
};