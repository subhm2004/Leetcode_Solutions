class Solution {
public:
    int dp[10005];
    vector<int> arr;   

    int solve(int i) {
        int n = arr.size();

        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int min_jumps = INT_MAX;
        int max_reach_limit = min(i + arr[i], n - 1);

        for (int next = i + 1; next <= max_reach_limit; next++) {
            int jumps = solve(next);

            if (jumps != INT_MAX)
                min_jumps = min(min_jumps, jumps + 1);
        }

        return dp[i] = min_jumps;
    }

    int jump(vector<int>& nums) {
        arr = nums;                  
        memset(dp, -1, sizeof(dp));   
        return solve(0);
    }
};