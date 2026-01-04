class Solution {
public:
    string s;
    long long dp[20][2][2][2];
    // dp[idx][tight][started][has_zero]

    long long solve(int idx, bool tight, bool started, bool has_zero) {
        if (idx == s.size()) {
            // valid if number started AND no zero appeared
            return (started && !has_zero) ? 1 : 0;
        }

        if (dp[idx][tight][started][has_zero] != -1) return dp[idx][tight][started][has_zero];

        int limit = tight ? s[idx] - '0' : 9;
        long long ans =0;

        for (int d = 0; d <= limit; d++) {
            bool updated_tight = tight && (d == limit);
            bool updated_started = started;
            bool updated_has_zero = has_zero;

            if (!started) {
                if (d != 0) {
                    updated_started = true;
                }
            } else {
                if (d == 0) {
                    updated_has_zero = true;
                }
            }

            ans += solve(idx + 1, updated_tight, updated_started, updated_has_zero);
        }

        return dp[idx][tight][started][has_zero] = ans;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, false, false);
    }
};
