class Solution {
public:
    int MOD = 1e9+7;
    int min_sum, max_sum;
    
    // dp[idx][sum][tight][started]
    int dp[23][401][2][2];

    int solve(string &s, int idx, int sum, bool tight, bool started) {
        // BC
        if (sum > max_sum) return 0;

        if (idx >= s.size()) {
            return (started && sum >= min_sum && sum <= max_sum) ? 1 : 0;
        }

        // Check if already computed dp states
        if (dp[idx][sum][tight][started] != -1) {
            return dp[idx][sum][tight][started];
        }

        long long ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool updated_tight = tight && (d == limit);
            bool updated_started = started || (d != 0);
            int updated_sum = sum + (updated_started ? d : 0);

            ans = (ans + solve(s, idx + 1, updated_sum, updated_tight, updated_started)) % MOD;
        }

        return dp[idx][sum][tight][started] = ans;
    }

    void subtract_minus_one(string &x) {
        int i = x.size() - 1;
        while (i >= 0 && x[i] == '0') {
            x[i] = '9';
            i--;
        }
        if (i >= 0) x[i]--;
    }

    int count_limit_to(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, true, false);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        this->min_sum = min_sum;
        this->max_sum = max_sum;

        subtract_minus_one(num1);

        long long r = count_limit_to(num2);
        long long l = (num1 == "0") ? 0 : count_limit_to(num1);

        long long ans = (r - l + MOD) % MOD;
        return ans;
    }
};