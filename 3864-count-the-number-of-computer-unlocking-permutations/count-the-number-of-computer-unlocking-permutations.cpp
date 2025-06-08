class Factorial {
public:
    typedef long long ll;
    const int M = 1e9 + 7;     // Prime Modulo
    const int N = 2e5 + 2;     // Upper limit for factorial

    vector<ll> fact;
    vector<ll> invFact;

    // Modular helper functions
    ll mod(ll x) { return ((x % M + M) % M); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    // Fermat's little theorem inverse
    ll inv(ll x) {
        return modPow(x, M - 2);
    }

    // Precompute factorials and inverse factorials
    void precalc() {
        fact.resize(N, 1);
        invFact.resize(N, 1);

        for (int i = 1; i < N; i++) {
            fact[i] = mul(fact[i - 1], i);
        }

        invFact[N - 1] = inv(fact[N - 1]);  // inverse factorial of N-1

        for (int i = N - 2; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    Factorial() {
        precalc();
    }

    // factorial n! % M
    ll factorial(ll n) {
        if (n < 0) return 0;
        return fact[n];
    }

    // inverse factorial (n!)^-1 % M
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

        // Check condition: sabhi complexity[i] (i>0) complexity[0] se strictly bade hone chahiye
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        // Agar condition satisfy hoti hai to answer (n-1)!
        return fact.factorial(n - 1);
    }
};