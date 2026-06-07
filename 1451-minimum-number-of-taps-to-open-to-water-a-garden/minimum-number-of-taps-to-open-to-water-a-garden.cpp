class Solution {
public:
    vector<pair<int, int>> intervals;
    vector<int> dp;

    int solve(int pos, int n) {

        if (pos >= n)
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        int ans = 1e9;

        for (auto &[left, right] : intervals) {

            // Current position ko cover karna chahiye
            // aur progress bhi honi chahiye
            if (left <= pos && pos < right) {

                int taps = solve(right, n);

                if (taps != 1e9) {
                    ans = min(ans, 1 + taps);
                }
            }
        }

        return dp[pos] = ans;
    }

    int minTaps(int n, vector<int>& ranges) {

        intervals.clear();

        for (int i = 0; i <= n; i++) {

            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            intervals.push_back({left, right});
        }

        dp.assign(n + 1, -1);

        int ans = solve(0, n);

        return (ans == 1e9) ? -1 : ans;
    }
};