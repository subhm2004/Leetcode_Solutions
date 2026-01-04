class Solution {
public:
    string s;
    static const int OFFSET = 200;
    long long dp[20][2][401][2][2][20];
    // idx, tight, diff, started, parity, digit_count

    long long solve(int idx, bool tight, int diff, bool started, bool parity,
                    int digit_count) {
        if (idx == s.size()) {
            return started && digit_count >= 2 && diff == 0;
        }

        if (dp[idx][tight][diff + OFFSET][started][parity][digit_count] != -1)
            return dp[idx][tight][diff + OFFSET][started][parity][digit_count];
        long long ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == limit);

            int updated_diff = diff;
            bool new_parity = parity;
            int updated_count = digit_count;

            if (updated_started) {
                updated_count++;
                if (parity)
                    updated_diff += d; // odd position
                else
                    updated_diff -= d; // even position
                new_parity = !parity;
            }

            ans += solve(idx + 1, updated_tight, updated_diff, updated_started,
                         new_parity, updated_count);
        }

        return dp[idx][tight][diff + OFFSET][started][parity][digit_count] =
                   ans;
    }

    long long count(long long x) {
        if (x <= 0)
            return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, 0, false, true, 0);
    }

    long long countBalanced(long long low, long long high) {
        return count(high) - count(low - 1);
    }
};
