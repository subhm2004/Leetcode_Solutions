class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            if (i + 2 >= n)
                return {};

            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Check all 3 pairwise differences
            if (abs(a - b) > k || abs(a - c) > k || abs(b - c) > k)
                return {};

            ans.push_back({a, b, c});
        }

        return ans;
    }
};