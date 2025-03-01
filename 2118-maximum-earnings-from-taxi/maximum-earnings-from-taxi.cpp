class Solution {
public:
    long long solveRE(int i, vector<vector<pair<int, int>>>& startToEndAndEarns) {
        if (i >= startToEndAndEarns.size()) return 0;

        long long skip = solveRE(i + 1, startToEndAndEarns);

        long long take = 0;
        for (auto& [end, earn] : startToEndAndEarns[i])
            take = max(take, earn + solveRE(end, startToEndAndEarns));

        return max(skip, take);
    }

    long long solveME(int i, vector<vector<pair<int, int>>>& startToEndAndEarns, vector<long long>& dp) {
        if (i >= startToEndAndEarns.size()) return 0;
        if (dp[i] != -1) return dp[i];

        long long skip = solveME(i + 1, startToEndAndEarns, dp);

        long long take = 0;
        for (auto& [end, earn] : startToEndAndEarns[i])
            take = max(take, earn + solveME(end, startToEndAndEarns, dp));

        return dp[i] = max(skip, take);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> startToEndAndEarns(n + 1);
        vector<long long> dp(n + 1, -1);

        for (vector<int>& ride : rides) {
            int start = ride[0], end = ride[1], tip = ride[2];
            int earn = end - start + tip;
            startToEndAndEarns[start].push_back({end, earn});
        }

        return solveME(1, startToEndAndEarns, dp);
    }
};
