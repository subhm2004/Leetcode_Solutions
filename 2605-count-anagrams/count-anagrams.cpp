class Combinatorics {
public:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime Modulo
    const int N = 1e5+2 ; // Factorial limit
    vector<ll> fact;

    ll mod(ll x) { return ((x % M + M) % M); }

    ll add(ll a, ll b) { return mod(a + b); }

    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b % 2)
                ans = mul(ans, a);
            a = mul(a, a);
            b /= 2;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }

    ll modSub(ll a, ll b) { return mod(a - b); }

    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

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
        return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
    }

    ll nPr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], inv(fact[n - r]));
    }

    ll factorial(ll r) {
        if (r < 0)
            return 0;
        return fact[r];
    }
};

class Solution : public Combinatorics {
public:
    ll getDistinctWays(string word) {
        unordered_map<char, ll> freq;
        for (auto& c : word) {
            freq[c]++;
        }

        ll n = word.length();
        ll ans = factorial(n);
        for (auto& entry : freq) {
            ll count = entry.second;
            if (count > 0) {
                ans = modDiv(ans, factorial(count));
            }
        }

        return ans;
    }

    int countAnagrams(string s) {
    int n = s.length();
    string word = "";
    ll ans = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            ans = mul(ans, getDistinctWays(word));  // Abhi tak ke word ka distinct ways calculate karo
            word = "";  // Next word ke liye word ko clear karo
        } else {
            word.push_back(s[i]);  // Current character ko word me add karo
        }
    }

    // Loop ke baad last word ka process karo
    ans = mul(ans, getDistinctWays(word));  

    return (int)ans;
}
};