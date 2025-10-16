class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr_count = 1;
        int prev_count = 0;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++curr_count;
            } else {
                prev_count = curr_count;
                curr_count = 1;
            }
            ans = max(ans, min(prev_count, curr_count));
            ans = max(ans, curr_count / 2);
        }
        return ans;
    }
};