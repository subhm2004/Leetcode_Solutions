class Solution {
public:
    int n;
    vector<vector<int>> dp;

     int solveRE(int i, bool deleted, vector<int>& nums) {
        if (i == n) return INT_MIN;

        // Case 1: Take current element and move forward
        int take = nums[i] + max(0, solveRE(i + 1, false, nums));

        int skip = INT_MIN;
        // Case 2: Try deleting this element (only if not yet deleted)
        if (!deleted) {
            skip = solveRE(i + 1, true, nums);  // skip current element
        }

        return max(take, skip);
    }

    int solveME(int i, bool deleted, vector<int>& nums) {
        if (i == n) return INT_MIN;

        if (dp[i][deleted] != INT_MIN) return dp[i][deleted];

        int take = nums[i] + max(0, solveME(i + 1, deleted, nums));

        int skip = INT_MIN;
        if (!deleted) {
            skip = solveME(i + 1, true, nums);
        }

        return dp[i][deleted] = max(take, skip);
    }

    int maximumSum(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MIN;
        dp.assign(n, vector<int>(2, INT_MIN)); // dp[i][0] = not deleted, dp[i][1] = deleted

        // sabhi index pr start kro 
        for (int i = 0; i < n; ++i) {
            // ans = max(ans, solveRE(i, false, nums));
            ans = max(ans, solveME(i, false, nums));
        }
        return ans;
    }
};
