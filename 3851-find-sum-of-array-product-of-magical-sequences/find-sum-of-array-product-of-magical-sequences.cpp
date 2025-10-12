class Combinatorics
{
public:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime Modulo
    const int N = 1e4+5; // Factorial limit
    vector<ll> fact, invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b)
    {
        ll ans = 1;
        while (b)
        {
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

    Combinatorics()
    {
        fact.resize(N, 1);
        invFact.resize(N, 1);
        precalc();
    }

    void precalc()
    {
        // Precompute factorials
        for (int i = 1; i < N; i++)
        {
            fact[i] = mul(fact[i - 1], i);
        }

        // Precompute inverse factorials using Fermat's little theorem
        invFact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
        {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    ll nCr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    ll nPr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], invFact[n - r]);
    }

    ll factorial(ll r)
    {
        if (r < 0)
            return 0;
        return fact[r];
    }

    ll inverse_factorial(ll r)
    {
        if (r < 0)
            return 0;
        return invFact[r];
    }
};

struct tuple_hash {
    size_t operator()(const tuple<long long, int, int, int>& t) const noexcept {
        auto [a, b, c, d] = t;
        size_t h1 = hash<long long>()(a);
        size_t h2 = hash<int>()(b);
        size_t h3 = hash<int>()(c);
        size_t h4 = hash<int>()(d);
        // XOR + bit shifting combine pattern
        return (((h1 ^ (h2 << 1)) ^ (h3 << 2)) ^ (h4 << 3));
    }
};


class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    int N, K;

    unordered_map<tuple<ll, int, int, int>, ll, tuple_hash> dp;
    /*
    Tuple = (binary_sum, m, k, i) ye hai key
    binary_sum → ab tak sequence me jo binary sum build hua hai (long long)
    m → abhi kitne elements sequence me choose karne hai
    k → abhi kitne set bits chahiye 
    i → current index in nums
    */
    Combinatorics C;

    ll solveME(ll binay_sum, int m, int k, int i, vector<int>& nums) {
        auto key = make_tuple(binay_sum, m, k, i);
        if (dp.count(key)) return dp[key];

        if (m == 0 && __builtin_popcountll(binay_sum) == k)
            return 1;
        if (m == 0 || i >= N)
            return 0;

        ll total_sum = 0;

        // Skip current index
        total_sum = (total_sum + solveME(binay_sum >> 1, m, k - (binay_sum & 1), i + 1, nums)) % MOD;

        // Take current index 'freq' times
        for (int freq = 1; freq <= m; freq++) {
            ll new_binary_sum = binay_sum + freq;
            ll prod = solveME(new_binary_sum >> 1, m - freq, k - (new_binary_sum & 1), i + 1, nums);
            prod = (C.modPow(nums[i], freq) % MOD * prod % MOD) % MOD;
            prod = (prod * C.nCr(m, freq)) % MOD;
            total_sum = (total_sum + prod) % MOD;
        }

        return dp[key] = total_sum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        N = nums.size();
        K = k;
        dp.clear();
        return (int)(solveME(0, m, k, 0, nums) % MOD);
    }
};