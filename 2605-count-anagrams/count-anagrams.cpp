class Combinatorics
{
public:
    typedef long long ll;
    const int M = 1e9 + 7;   // Prime Modulo
    const int N = 1e5 + 2;   // Factorial limit

    vector<ll> fact, invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1) ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics()
    {
        fact.assign(N, 1);
        invFact.assign(N, 1);
        precalc();
    }

    void precalc()
    {
        for (int i = 1; i < N; i++)
            fact[i] = mul(fact[i - 1], i);

        invFact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
            invFact[i] = mul(invFact[i + 1], i + 1);
    }

    ll nCr(ll n, ll r)
    {
        if (r > n || r < 0) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    ll nPr(ll n, ll r)
    {
        if (r > n || r < 0) return 0;
        return mul(fact[n], invFact[n - r]);
    }

    ll factorial(ll r)
    {
        if (r < 0) return 0;
        return fact[r];
    }

    ll inverse_factorial(ll r)
    {
        if (r < 0) return 0;
        return invFact[r];
    }

    ll get_Distinct_Ways(const string &word)
    {
        unordered_map<char, ll> freq;
        for (char c : word) freq[c]++;

        ll ways = factorial(word.size());
        for (auto &e : freq)
            ways = mul(ways, invFact[e.second]);

        return ways;
    }
};

class Solution : public Combinatorics
{
public:
    int countAnagrams(string s)
    {
        ll ans = 1;
        string word;

        for (char c : s)
        {
            if (c == ' ')
            {
                ans = mul(ans, get_Distinct_Ways(word));
                word.clear();
            }
            else
            {
                word.push_back(c);
            }
        }

        ans = mul(ans, get_Distinct_Ways(word));
        return (int)ans;
    }
};
