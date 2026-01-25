class Solution {
public:
    long long dp[12][2][2]; // dp[idx][tight][started]
    vector<int> D;
    string s;

    long long solve(int idx, bool tight, bool started) {
        if (idx >= s.size())
            return started ? 1 : 0;

        if (dp[idx][tight][started] != -1)
            return dp[idx][tight][started];
        long long ans = 0;

        int limit = tight ? (s[idx] - '0') : 9;

        // Case-A: Skip digit (only if number not started yet)
        if (!started) {
            ans += solve(idx + 1, false, false);
        }

        // Case-B: Place a digit from D
        for (int d : D) {
            if (d > limit)
                break;

            bool updated_tight = tight && (d == limit);
            ans += solve(idx + 1, updated_tight, true);
        }

        return dp[idx][tight][started] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));

        s = to_string(n);
        for (auto& x : digits)
            D.push_back(x[0] - '0');

        return solve(0, true, false);
    }
};