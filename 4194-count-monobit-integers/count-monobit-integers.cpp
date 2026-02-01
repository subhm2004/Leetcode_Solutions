class Solution {
public:
    string s;
    long long dp[32][2][2][2];

    long long solve(int idx, int tight, int started, int bit) {

        if (idx == s.size()) {
            // number ban gaya
            return 1;
        }

        if (dp[idx][tight][started][bit] != -1) return dp[idx][tight][started][bit];

        long long ans = 0;

        int limit = tight ? (s[idx] - '0') : 1;

        for (int b = 0; b <= limit; b++) {

            int updated_tight = tight && (b == limit);
            int updated_started = started || (b != 0);

            if (!started) {

                if (!updated_started) {
                    // abhi bhi leading zero
                    ans += solve(idx + 1, updated_tight, 0, bit);
                } else {
                    // number start ho gaya
                    ans += solve(idx + 1, updated_tight, 1, b);
                }

            } else {

                // already started -> saare bits same hone chahiye
                if (b == bit) {
                    ans += solve(idx + 1, updated_tight, 1, bit);
                }
            }
        }

        return dp[idx][tight][started][bit] = ans;
    }

    int countMonobit(int n) {

        s = bitset<32>(n).to_string();
        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0, 0);
    }
};
