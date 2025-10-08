class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        int first_value = (left != nums.end()) ? *left : -1;
        if (first_value != target)
            return {-1, -1};
        return {int(left - nums.begin()), int(right - nums.begin() - 1)};
    }
};
