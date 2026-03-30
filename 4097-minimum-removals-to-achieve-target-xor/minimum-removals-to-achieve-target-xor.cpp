// minimum removals = n - (max subset size whose xor is equal to target)
class Solution {
public:
    vector<vector<int>> dp;

// ye function find krta hai length of max_subset whose xor is equal to target
    int solve(int i, int curr_xor, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return (curr_xor == target) ? 0 : INT_MIN/2; // -INF
        }

        if (dp[i][curr_xor] != -1)
            return dp[i][curr_xor];

        // include
        int include = 1 + solve(i + 1, curr_xor ^ nums[i], nums, target);

        // exclude
        int exclude = solve(i + 1, curr_xor, nums, target);

        return dp[i][curr_xor] = max(include, exclude);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        // int maxVal = *max_element(nums.begin(), nums.end());
        // maxVal = max({maxVal, target, 1}); // Fix : 0 aur target dono handle

        // int bits = log2(maxVal) + 1;
        // int MAXX = 1 << bits;

        // max max value ho skti hai 10^4 tak mltb ki ise likha ja skta hai 2^14 tak
        int MAXX = 1 << 14;
        dp.assign(n + 1, vector<int>(MAXX, -1));

        int max_subset = solve(0, 0, nums, target); // max subset size whose xor equal to target

        if (max_subset < 0)
            return -1;

        return n - max_subset;
    }
};