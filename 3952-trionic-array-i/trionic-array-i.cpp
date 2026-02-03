class Solution {
public:
    bool is_strictly_increasing(const vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool is_strictly_decreasing(const vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] <= nums[i + 1])
                return false;
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

         for (int p = 1; p < n - 2; ++p) {
            if (!is_strictly_increasing(nums, 0, p)) continue;

            for (int q = p + 1; q < n - 1; ++q) {
                if (is_strictly_decreasing(nums, p, q) && is_strictly_increasing(nums, q, n - 1))
                    return true;
            }
        }

        return false;
    }
};
