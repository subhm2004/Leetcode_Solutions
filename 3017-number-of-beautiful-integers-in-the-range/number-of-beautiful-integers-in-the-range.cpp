class Solution {
public:
    int k;
    long long dp[12][2][21][25][2];
    static const int OFFSET = 12;

    long long solve(string& s, int idx, bool tight, int rem, int diff,
                    bool started) {
        if (idx == s.size()) {
            return started && diff == 0 && rem == 0;
        }

        if (dp[idx][tight][rem][diff + OFFSET][started] != -1)
            return dp[idx][tight][rem][diff + OFFSET][started];

        int limit = tight ? s[idx] - '0' : 9;

        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newStarted = started || (d != 0);
            bool newTight = tight && (d == limit);

            int newRem = rem;
            int newDiff = diff;

            if (newStarted) {
                newRem = (rem * 10 + d) % k;
                if (d % 2 == 0)
                    newDiff++;
                else
                    newDiff--;
            }

            ans += solve(s, idx + 1, newTight, newRem, newDiff, newStarted);
        }

        return dp[idx][tight][rem][diff + OFFSET][started] = ans;
    }

    long long count_beautiful(long long x, int k) {
        if (x <= 0)
            return 0;
        string s = to_string(x);
        this->k = k;
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, true, 0, 0, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        return count_beautiful(high, k) - count_beautiful(low - 1, k);
    }
};
