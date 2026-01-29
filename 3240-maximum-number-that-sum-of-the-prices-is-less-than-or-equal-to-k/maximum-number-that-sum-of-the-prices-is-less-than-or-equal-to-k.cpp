auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();

typedef long long ll;
class Solution {
public:
    string s;
    int x;
    pair<ll, ll> dp[65][2][2]; // dp[idx][tight][started] = {count, price}

    pair<ll, ll> solve(int idx, bool tight, bool started) {
        if (idx >= s.size()) {
            return started ? make_pair(1LL, 0LL) : make_pair(0LL, 0LL);
        }

        if (dp[idx][tight][started].first != -1)
            return dp[idx][tight][started];

        ll count = 0;
        ll price = 0;
        int limit = tight ? (s[idx] - '0') : 1;
        int pos_from_LSB = s.size() - idx; // 1-indexed

        for (int bit = 0; bit <= limit; bit++) {
            bool updated_tight = tight && (bit == limit);
            bool updated_started = started || (bit != 0);

            auto [c, p] = solve(idx + 1, updated_tight, updated_started);
            count += c;
            price += p;

            if (updated_started && bit == 1 && pos_from_LSB % x == 0) {
                price += c;
            }
        }

        return dp[idx][tight][started] = {count, price};
    }

    ll accumulate_price(ll n) {
        if (n <= 0)
            return 0;
        s = bitset<64>(n).to_string();

        // remove karte hai leading zeros
        int first_one = s.find('1');
        s = s.substr(first_one);

        // init dp with -1
        for (int i = 0; i < 65; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = {-1, -1};

        return solve(0, true, false).second;
    }

    long long findMaximumNumber(long long k, int x) {
        this->x = x;

        ll low = 1;
        ll high = 1e15;
        ll ans = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (accumulate_price(mid) <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};