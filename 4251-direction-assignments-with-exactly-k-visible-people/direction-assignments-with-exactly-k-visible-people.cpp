class Combinatorics {
public:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime Modulo
    const int N = 1e5 + 2; // Factorial limit

    vector<ll> fact, invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1)
                ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics() {
        fact.assign(N, 1);
        invFact.assign(N, 1);
        precalc();
    }

    void precalc() {
        for (int i = 1; i < N; i++)
            fact[i] = mul(fact[i - 1], i);

        invFact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
            invFact[i] = mul(invFact[i + 1], i + 1);
    }

    ll nCr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    ll nPr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], invFact[n - r]);
    }

    ll factorial(ll r) {
        if (r < 0)
            return 0;
        return fact[r];
    }

    ll inverse_factorial(ll r) {
        if (r < 0)
            return 0;
        return invFact[r];
    }
};

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countVisiblePeople(int n, int pos, int k) {
        Combinatorics comb;

        int ways = comb.nCr(n - 1, k);
        return ((ways * 2) % MOD);
    }
};