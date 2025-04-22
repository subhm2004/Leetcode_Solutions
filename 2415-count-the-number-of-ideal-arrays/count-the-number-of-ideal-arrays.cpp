class Combinatorics {
protected:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime modulus
    const int N = 2e5 + 2; // Factorial limit
    vector<ll> fact;

    ll mod(ll x) { return ((x % M + M) % M); }

    ll add(ll a, ll b) { return mod(a + b); }

    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b % 2)
                res = mul(res, a);
            a = mul(a, a);
            b /= 2;
        }
        return res;
    }

    ll inv(ll x) { return modPow(x, M - 2); }

    ll modSub(ll a, ll b) { return mod(a - b); }

    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

public:
    Combinatorics() {
        fact.resize(N, 1);
        precalc();
    }

    void precalc() {
        for (int i = 1; i < N; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
    }

    ll nCr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mod(mul(fact[n], mul(inv(fact[r]), inv(fact[n - r]))));
    }

    ll nPr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mod(mul(fact[n], inv(fact[n - r])));
    }

    ll factorial(ll r) {
        if (r < 0 || r >= N)
            return 0;
        return mod(fact[r]);
    }
};

class Solution : public Combinatorics {
    const int M = 1e9 + 7;
    int n, maxValue;
    unordered_map<int, vector<long long>> dp;

    long long dfs(int val, int len) {
        if (len == 1) return 1;
        if (dp[val][len] != -1) return dp[val][len];

        long long res = 0;
        for (int mult = 2 * val; mult <= maxValue; mult += val) {
            res = add(res, dfs(mult, len - 1));
        }

        return dp[val][len] = res;
    }

public:
    int idealArrays(int n_, int maxValue_) {
        n = n_;
        maxValue = maxValue_;
        int maxLen = 14;

        // initialize dp
        for (int i = 1; i <= maxValue; ++i)
            dp[i] = vector<long long>(maxLen + 1, -1);

        long long ans = 0;
        for (int val = 1; val <= maxValue; ++val) {
            for (int len = 1; len <= maxLen; ++len) {
                long long ways = dfs(val, len);
                long long pos = nCr(n - 1, len - 1);
                ans = add(ans, mul(ways, pos));
            }
        }

        return ans;
    }
};
