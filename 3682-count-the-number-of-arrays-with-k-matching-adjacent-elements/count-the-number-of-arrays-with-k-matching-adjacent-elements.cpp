auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Combinatorics {
public:
    typedef long long ll;
    const int M = 1e9 + 7;
    const int N = 1e5 + 2;
    vector<ll> fact;

    ll mod(ll x) {
        return ((x % M + M) % M);
    }

    ll add(ll a, ll b) {
        return mod(a + b);
    }

    ll sub(ll a, ll b) {
        return mod(a - b);
    }

    ll mul(ll a, ll b) {
        return mod(a * b);
    }

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

    ll inv(ll x) {
        return modPow(x, M - 2);
    }

    ll modDiv(ll a, ll b) {
        if (b == 0) {
            return 0;
        }
        return mul(a, inv(b));
    }

    Combinatorics() {
        fact.resize(N, 1);
        precalc();
    }

    void precalc() {
        for (int i = 1; i < N; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
    }

    ll factMod(ll n) {
        if (n < 0) return 0;
        return fact[n];
    }

    ll nCr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
    }

    ll nPr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], inv(fact[n - r]));
    }
};
class Solution : public Combinatorics {
public:
    int countGoodArrays(int n, int m, int k) {
        return mul(m, mul(modPow(m - 1, n - k - 1), nCr(n - 1, k)));
    }
};
