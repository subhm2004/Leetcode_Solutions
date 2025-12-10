class Factorial {
public:
    typedef long long ll;
    const int M = 1e9 + 7;
    const int N = 1e5 + 1;

    vector<ll> fact;
    vector<ll> invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll my_pow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    ll inv(ll x) {
        return my_pow(x, M - 2);
    }

    void precalc() {
        fact.resize(N, 1);
        invFact.resize(N, 1);

        for (int i = 1; i < N; i++) {
            fact[i] = mul(fact[i - 1], i);
        }

        invFact[N - 1] = inv(fact[N - 1]);

        for (int i = N - 2; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    Factorial() {
        precalc();
    }

    ll factorial(ll n) {
        if (n < 0) return 0;
        return fact[n];
    }

    ll inverse_factorial(ll n) {
        if (n < 0) return 0;
        return invFact[n];
    }
};

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        Factorial fact;

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }
        return fact.factorial(n - 1);
    }
};
