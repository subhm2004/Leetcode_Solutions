class Solution {
public:
    static const int MOD = 1e9 + 7;
    string s;
    long long dp[105][2][2][10];

    long long solve(int idx, bool tight, bool started, int last_digit) {
        if (idx >= s.size()) {
            return started ? 1 : 0;
        }

        if (dp[idx][tight][started][last_digit] != -1)
            return dp[idx][tight][started][last_digit];

        int limit = tight ? s[idx] - '0' : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == limit);

            if (!started) {
                // still leading zeros
                if (d == 0) {
                    ans = (ans + solve(idx + 1, updated_tight, false, 0)) % MOD;
                } else {
                    // start number
                    ans = (ans + solve(idx + 1, updated_tight, true, d)) % MOD;
                }
            } else {
                // number already started
                if (abs(d - last_digit) == 1) {
                    ans = (ans + solve(idx + 1, updated_tight, true, d)) % MOD;
                }
            }
        }

        return dp[idx][tight][started][last_digit] = ans;
    }

    long long count(string& str) {
        s = str;
        memset(dp, -1, sizeof(dp));
        return solve(0, true, false, 0);
    }

    string minus_one(string& x) {
        if (x == "0")
            return "0";

        int i = x.size() - 1;
        while (x[i] == '0') {
            x[i] = '9';
            i--;
        }
        x[i]--;

        if (x[0] == '0')
            x.erase(0, 1);
        return x;
    }

    int countSteppingNumbers(string low, string high) {
        int right = count(high);
        string low_minus_one = minus_one(low);
        int left = count(low_minus_one);
        return (right - left + MOD) % MOD;
    }
};