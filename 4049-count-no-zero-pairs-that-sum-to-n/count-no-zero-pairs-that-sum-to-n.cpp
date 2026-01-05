class Solution {
public:
    string s;
    long long dp[20][20][2][2];
    // dp[idx][carry][started_a][started_b]

    long long solve(int idx, int carry, bool started_a, bool started_b) {

        // saare digits process ho gaye
        if (idx >= s.length()) {
            // extra carry allowed nahi
            return (carry == 0);
        }

        if (dp[idx][carry][started_a][started_b] != -1)
            return dp[idx][carry][started_a][started_b];

        long long ans = 0;

        int limit = s[idx] - '0';

        // a ke digit ka range
        int start_a = (idx == 0 ? 1 : 0); // a > 0
        int end_a = (started_a ? 0 : 9);  // zero aa gaya to aage sirf zero

        // b ke digit ka range
        int start_b = (idx == 0 ? 1 : 0); // b > 0
        int end_b = (started_b ? 0 : 9);

        for (int da = start_a; da <= end_a; da++) {


            for (int db = start_b; db <= end_b; db++) {
            bool updated_started_a = started_a || (da == 0);

                bool updated_started_b = started_b || (db == 0);

                int sum = da + db + carry;
                int updated_carry = sum / 10;
                if (sum % 10 == limit) {
                    ans += solve(idx + 1, updated_carry, updated_started_a ,updated_started_b);
                }
            }
        }

        return dp[idx][carry][started_a][started_b] = ans;
    }

    long long countNoZeroPairs(long long n) {
        s = to_string(n);
        reverse(s.begin(), s.end()); // Right → Left (LSB first)
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, false, false);
    }
};
