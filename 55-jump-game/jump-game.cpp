class Solution {
public:
    vector<int> arr;
    int dp[10005];

    bool solve(int idx) {
        int n = arr.size();

        if (idx >= n - 1)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        int max_reach_limit = min(idx + arr[idx], n - 1);

        // try all possible jumps
        for (int next_idx = idx + 1; next_idx <= max_reach_limit; next_idx++) {

            if (solve(next_idx) == true)
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        arr = nums;  
        memset(dp, -1, sizeof(dp));

        return solve(0);
    }
};