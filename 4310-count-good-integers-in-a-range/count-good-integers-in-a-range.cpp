class Solution {
public:
    long long dp[16][11][2][2];
    string s;
    int k;

    long long solve(int idx, int prev_digit, bool tight, bool started) {

        if (idx >= s.size()) {
            return started;
        }

        int prev = prev_digit + 1;

        if (dp[idx][prev][tight][started] != -1) {
            return dp[idx][prev][tight][started];
        }

        long long ans = 0;

        int limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {

            bool updated_tight = tight && (d == limit);
            bool updated_started = started || (d != 0);

            if (!updated_started) {

                ans += solve(idx + 1, -1, updated_tight, false);
            }
            else {

                if (prev_digit == -1 || abs(prev_digit - d) <= k) {

                    ans += solve(idx + 1, d, updated_tight, true);
                }
            }
        }

        return dp[idx][prev][tight][started] = ans;
    }

    long long countGood(long long num) {

        if (num < 0)
            return 0;

        s = to_string(num);

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, true, false);
    }

    long long goodIntegers(long long l, long long r, int k) {

        this->k = k;

        return countGood(r) - countGood(l - 1);
    }
};