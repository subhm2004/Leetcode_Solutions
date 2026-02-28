// -A <= expression <= A ye hai to abs(expression) <= A
class Solution {
public:
    int n;
    int dp[1001];
    vector<int> nums;

    int dfs(int i, int target) {

        if (i == n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int best = -1000000000;

        for (int j = i + 1; j < n; j++) {

            if (abs(nums[j] - nums[i]) <= target) {
                best = max(best, 1 + dfs(j, target));
            }
        }

        return dp[i] = best;
    }

    int maximumJumps(vector<int>& arr, int target) {

        nums = arr;
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        int ans = dfs(0, target);

        return (ans < 0) ? -1 : ans;
    }
};