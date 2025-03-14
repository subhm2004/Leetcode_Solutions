class Solution {
public:
    int count(vector<int>& nums, int mid) {
        int operations = 0;
        for (auto num : nums) {
            operations += (num - 1) / mid;
        }
        return operations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(nums, mid) <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
