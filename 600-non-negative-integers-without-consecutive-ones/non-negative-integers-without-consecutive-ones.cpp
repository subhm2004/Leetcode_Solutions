class Solution {
public:
    int dp[35][2][2];
    string s;

    int solve(int idx, bool tight, bool prev_one) {
        if (idx >= s.size()) {
            return 1; // valid number
        }

        if (dp[idx][tight][prev_one] != -1)
            return dp[idx][tight][prev_one];

        int limit = tight ? (s[idx] - '0') : 1;
        int ans = 0;
        for (int d = 0; d <= limit; d++) {
            int updated_tight = tight && (d == limit);

            // consecutive ones allowed nhi h
            if (prev_one && d == 1)
                continue;

            ans += solve(idx + 1, updated_tight, d == 1);
        }
        return dp[idx][tight][prev_one] = ans;
    }

    int findIntegers(int n) {
        // convert n to binary string s
        s.clear();
        s = bitset<32>(n).to_string();


        //CONVENTIONAL METHOD OF CONVERSION

        // s.clear();
        // while (n > 0) {
        //     s.push_back((n & 1) + '0');
        //     n >>= 1;
        // }
        // reverse(s.begin(), s.end());

        memset(dp, -1, sizeof(dp));
        return solve(0, true, false);
    }
};
