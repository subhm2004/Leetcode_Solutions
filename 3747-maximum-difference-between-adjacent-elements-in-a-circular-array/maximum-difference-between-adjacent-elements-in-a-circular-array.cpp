class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max_difference = 0;

        for (int i = 0; i < n; ++i) {
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            max_difference = max(max_difference, diff);
        }
        return max_difference;
    }
};
