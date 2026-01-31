class Solution {
public:
    using ll = long long;

    string s;
    int L, half;

    // dp[idx][diff+OFFSET][tight][started]
    ll dp[20][200][2][2];

    static const int OFFSET = 90;

    ll solve(int idx, int diff, bool tight, bool started)
    {
        if (idx == L)
        {
            return (started && diff == 0);
        }

        if (dp[idx][diff+OFFSET][tight][started] != -1) return dp[idx][diff+OFFSET][tight][started];

        ll ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++)
        {
            bool updated_started = started || (d != 0);

            if (!started && d == 0)
                continue;

            bool updated_tight = tight && (d == limit);

            int updated_diff = diff;
            
            if (idx < half) updated_diff += d;
            else            updated_diff -= d;

            ans += solve(idx + 1, updated_diff, updated_tight, updated_started);
        }

        return dp[idx][diff+OFFSET][tight][started] = ans;
    }

    ll count_up_to(ll x)
    {
        if (x <= 0) return 0;

        string t = to_string(x);
        int n = t.size();

        ll ans = 0;

        for (int len = 2; len < n; len += 2)
        {
            L = len;
            half = L / 2;
            s = string(L, '9');

            memset(dp, -1, sizeof(dp));
            ans += solve(0, 0, false, false);
        }

        if (n % 2 == 0)
        {
            L = n;
            half = L / 2;
            s = t;

            memset(dp, -1, sizeof(dp));
            ans += solve(0, 0, true, false);
        }

        return ans;
    }

    int countSymmetricIntegers(int low, int high)
    {
        return count_up_to(high) - count_up_to(low - 1);
    }
};
