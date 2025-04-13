class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> nextNums;

        for (int i = 0; i < n / 2; ++i) {
            if (i % 2 == 0)
                nextNums.push_back(min(nums[2 * i], nums[2 * i + 1]));
            else
                nextNums.push_back(max(nums[2 * i], nums[2 * i + 1]));
        }

        return solve(nextNums);
    }

    int minMaxGame(vector<int>& nums) { return solve(nums); }
};
