class Solution {
public:
/*
Agar k numbers hain, to: (start - k -1 ) - start + 1 = k elements
Unke indexes → start se start + k - 1 tak
Unke comparisons → ek less, yani start se start + k - 2 tak
*/
    bool is_strictly_increasing(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        for (int i = 0; i + 2 * k <= n; i++) {
            if (is_strictly_increasing(nums, i, k) &&
                is_strictly_increasing(nums, i + k, k))
                return true;
        }
        return false;
    }
};
