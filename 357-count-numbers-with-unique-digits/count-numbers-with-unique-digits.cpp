class Solution {
public:
    string s;
    long long dp[20][2][1024][2];
    // dp[idx][tight][mask][started]

    long long solve(int idx, bool tight, int mask, bool started) {
        // base case: saare digits process ho gaye
        if (idx == s.size()) {
            // agar number bana hai to valid
            return started ? 1 : 0;
        }
        if (dp[idx][tight][mask][started] != -1)
            return dp[idx][tight][mask][started];

        int limit = tight ? (s[idx] - '0') : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == limit);

            // CASE 1: abhi tak number start nahi hua (leading zeros)
            if (!updated_started) {
                // leading zero hai, mask touch nahi karna
                ans += solve(idx + 1, updated_tight, mask, false);
            }
            // CASE 2: number start ho chuka hai
            else {
                // agar digit repeat ho raha hai, skip
                if (mask & (1 << d))
                    continue;

                // digit ko mask me mark karke aage jao
                ans += solve(idx + 1, updated_tight, mask | (1 << d), true);
            }
        }

        return dp[idx][tight][mask][started] = ans;
    }

    int count_unique(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, 0, false);
    }
    int countNumbersWithUniqueDigits(int n) { return 1 + count_unique(pow(10,n)-1); }
};