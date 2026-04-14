class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> types;
    vector<vector<int>> dp;

    int solve(int i, int target) {

        // Exact target ban gaya
        if (target == 0)
            return 1;

        // Sare types khatam ho gaye
        if (i == types.size())
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int count = types[i][0];
        int marks = types[i][1];

        long long ways = 0;

        // 0 se count tak questions le sakte hain
        for (int take = 0; take <= count; take++) {

            int earned_marks = take * marks;

            if (earned_marks <= target) {
                ways = (ways + solve(i + 1, target - earned_marks)) % MOD;
            }
        }

        return dp[i][target] = ways;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {

        this->types = types;

        int n = types.size();

        dp.assign(n + 1, vector<int>(target + 1, -1));

        return solve(0, target);
    }
};