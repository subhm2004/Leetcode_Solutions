class Solution {
public:
    // dp[idx][prev1+1][prev2+1][tight][started][waviness]
    long long dp[16][25][25][2][2][16];
    string s;

    long long solve(int idx, int prev1, int prev2, bool tight, bool started, int waviness) {
        // prev1 and prev2: -1 mtlb not set, 0-9 are actual digits

        if (idx >= s.size()) {
            return started ? waviness : 0;
        }

        //(add 1 to handle -1)
        int p1 = prev1 + 1;
        int p2 = prev2 + 1;

        if (dp[idx][p1][p2][tight][started][waviness] != -1) {
            return dp[idx][p1][p2][tight][started][waviness];
        }

        long long ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool updated_tight = tight && (d == limit);
            bool updated_started = started || (d > 0);
            int updated_waviness = waviness;

            // Check krte hai if prev1 forms a peak or valley
            // Only check jab started hai or valid prev1 and prev2 hai
            if (updated_started && prev2 != -1 && prev1 != -1) {
                if (prev1 > prev2 && prev1 > d) {
                    updated_waviness++; // prev1 peak hai
                } else if (prev1 < prev2 && prev1 < d) {
                    updated_waviness++; // prev1 valley hai
                }
            }

            // Update karte hai prev1 or prev2 iff started
            int updated_prev1 = updated_started ? d : -1;
            int updated_prev2 = updated_started ? prev1 : -1;

            ans += solve(idx + 1, updated_prev1, updated_prev2, updated_tight, updated_started, updated_waviness);
        }

        return dp[idx][p1][p2][tight][started][waviness] = ans;
    }

    long long count_waviness(long long num) {
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, true, false, 0);
    }
    long long totalWaviness(long long num1, long long num2) {
        long long sum2 = count_waviness(num2);
        long long sum1 = (num1 == 0) ? 0 : count_waviness(num1 - 1);
        return sum2 - sum1;
    }
};