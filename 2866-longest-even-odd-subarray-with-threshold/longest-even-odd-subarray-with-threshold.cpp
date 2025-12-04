class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 0;            // sliding window left pointer
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Rule 1: value must not exceed threshold
            if (nums[right] > threshold) {
                left = right + 1;       // reset window
                continue;
            }

            // Rule 2: starting element must be even
            if (left == right) {
                if (nums[right] % 2 != 0) {
                    left = right + 1;   // odd cannot start window
                }
                ans = max(ans, right - left + 1);
                continue;
            }

            // Rule 3: parity must alternate
            if ((nums[right] % 2) == (nums[right - 1] % 2)) {
                // parity failed → start new window at current
                if (nums[right] % 2 == 0)
                    left = right;       // restart here
                else
                    left = right + 1;   // odd can't start
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
