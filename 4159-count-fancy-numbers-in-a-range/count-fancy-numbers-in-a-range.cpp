class Solution {
public:
    long long dp[16][11][4][2][2][140]; // dp[idx][prev_digit+1][dir+1][tight][started][sum]
    string s;

    bool goodDigits(int x) {

        string s = to_string(x);

        if (s.size() == 1) return true;

        bool incresing = true;
        bool decresing = true;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] <= s[i - 1])
                incresing = false;
            if (s[i] >= s[i - 1])
                decresing = false;
        }

        return incresing || decresing;
    }

    long long solve(int idx, int prev_digit, int dir, bool tight, bool started, int sum) {

        if (idx == s.size()) {

            if (!started)
                return 0;

            if (dir != 3)
                return 1;

            return goodDigits(sum);
        }

        int p = prev_digit + 1;

        if (dp[idx][p][dir][tight][started][sum] != -1)
            return dp[idx][p][dir][tight][started][sum];

        long long ans = 0;

        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool updated_tight = tight && (d == limit);
            bool updated_started = started || (d != 0);

            int updated_prev = prev_digit;
            int updated_dir = dir;
            int updated_sum = sum;

            if (updated_started) {

                updated_sum += d;

                if (!started) {
                    updated_prev = d;
                } else {

                    if (dir == 0) {

                        if (d > prev_digit)
                            updated_dir = 1;
                        else if (d < prev_digit)
                            updated_dir = 2;
                        else
                            updated_dir = 3;
                    } else if (dir == 1) {

                        if (d <= prev_digit)
                            updated_dir = 3;
                    } else if (dir == 2) {

                        if (d >= prev_digit)
                            updated_dir = 3;
                    }

                    updated_prev = d;
                }
            }

            ans += solve(idx + 1, updated_prev, updated_dir, updated_tight, updated_started, updated_sum);
        }

        return dp[idx][p][dir][tight][started][sum] = ans;
    }

    long long count(long long x) {

        s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, 0, true, false, 0);
    }

    long long countFancy(long long l, long long r) {

        return count(r) - count(l - 1);
    }
};