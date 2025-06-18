class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Check differences (nums[i+2] - nums[i] krke dekh lo agar ye hi
            // range me aa gya to baki sare to aayenge hi kyoki sort kr diya hai
            // humne vector to)
            if (abs(a - c) > k)
                return {};

            ans.push_back({a, b, c});
        }

        return ans;
    }
};