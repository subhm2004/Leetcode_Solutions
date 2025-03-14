class Solution {
public:
    bool helper(vector<int>& nums, int maxVal) {
        long extra = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            extra = max(0L, extra + nums[i] - maxVal);
        }
        return nums[0] + extra <= maxVal;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) >> 1;
            if (helper(nums, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
