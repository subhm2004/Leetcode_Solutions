// Digit DP se ho jati hai iff 1 <= n <= 10^15 or  10^22 or 10^25 advanced solution 
class Solution {
public:
    string s;
    int dp[12][2][2][2]; 
    // idx, tight, has_good, started

    bool bad_digit(int d) {
        return d == 3 || d == 4 || d == 7 ;
    }

    bool good_digit(int d) {
        return d == 2 || d == 5 || d == 6 || d == 9 ;
    }

    int solve(int idx, bool tight, int has_good, bool started) {
        if (idx == s.size()) {
            // number should actually exist AND be good
            return (started && has_good);
        }

        if (dp[idx][tight][has_good][started] != -1) return dp[idx][tight][has_good][started];

        int ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int updated_tight = tight && (d == limit);
            int updated_started = started || (d != 0);
            int updated_has_good = has_good;

            if (updated_started) {
                if (bad_digit(d)) continue;
                if (good_digit(d)) updated_has_good = 1;
            }

            ans += solve(idx + 1, updated_tight, updated_has_good, updated_started);
        }
        return dp[idx][tight][has_good][started] = ans;
    }

    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, 0, false);
    }
};
