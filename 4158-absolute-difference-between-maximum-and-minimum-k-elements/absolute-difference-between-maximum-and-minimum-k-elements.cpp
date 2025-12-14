class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int sum_left = 0, sum_right = 0;

        while (k--) {
            sum_left += nums[left++];
            sum_right += nums[right--];
        }

        return abs(sum_right - sum_left);
    }
};
