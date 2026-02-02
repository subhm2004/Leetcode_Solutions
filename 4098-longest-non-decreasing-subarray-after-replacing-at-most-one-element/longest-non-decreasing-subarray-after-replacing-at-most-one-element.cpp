class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }

        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, left[i]);

        for (int i = 0; i < n; i++) {

            int best = 1;

            if (i > 0) best = max(best, left[i - 1] + 1);
            if (i + 1 < n) best = max(best, right[i + 1] + 1);

            if (i > 0 && i + 1 < n) {
                if (nums[i - 1] <= nums[i + 1]) {
                    best = max(best, left[i - 1] + 1 + right[i + 1]);
                }
            }

            ans = max(ans, best);
        }

        return ans;
    }
};
