class Solution {
public:
    int longest_subarray_with_sum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int curr_sum = 0;
        int max_len = -1;

        for (int right = 0; right < n; right++) {
            curr_sum += nums[right];

            while (left <= right && curr_sum > target) {
                curr_sum -= nums[left];
                left++;
            }
            if (curr_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        return max_len;
    }

    int minOperations(vector<int>& nums, int x) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int target = total_sum - x;

        if (target < 0)
            return -1;
        if (target == 0)
            return nums.size();

        int length = longest_subarray_with_sum(nums, target);
        if (length == -1)
            return -1;

        return nums.size() - length;
    }
};
