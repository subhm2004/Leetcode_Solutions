class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;

        for (int start = 0; start < n; ++start) {
            int windowSum = 0;

            for (int end = start; end < n; ++end) {
                windowSum += nums[end];
                int length = end - start + 1;

                if (length >= l && length <= r && windowSum > 0) {
                    minSum = min(minSum, windowSum);
                }

                if (length > r) {
                    break;
                }
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
