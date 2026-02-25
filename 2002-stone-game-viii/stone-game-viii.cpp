class Solution {
public:
    vector<int> prefix;
    int dp[100005];
    int n;

    int solve(int i) {

        if (i == n)
            return prefix[n];

        if (dp[i] != -1)
            return dp[i];
        
        // two choices

        int include = prefix[i] - solve(i + 1);
        // exclude ka mtlb hai abhi smallest possible move nahi le raha, future ka bada move choose kar raha hai
        int exclude = solve(i + 1);
        return dp[i] = max(include, exclude);
    }

    int stoneGameVIII(vector<int>& stones) {

        n = stones.size();

        // 1-based prefixix sum
        prefix.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + stones[i - 1];

        memset(dp, -1, sizeof(dp));

        return solve(2); // first move minimum 2 stones
    }
};