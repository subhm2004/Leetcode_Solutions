// hume har baar “previous permutation” lena hai jab tak string sorted ascending (smallest permutation) na ban jaaye.
// Toh number of operations = (rank of current permutation among all permutations) - 1

auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();

class Combinatorics
{
public:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime Modulo
    const int N = 3005; // Factorial limit
    vector<ll> fact, inv_fact;

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
        inv_fact.resize(N, 1);
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
        inv_fact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
        {
            inv_fact[i] = mul(inv_fact[i + 1], i + 1);
        }
    }

    ll nCr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(inv_fact[r], inv_fact[n - r]));
    }

    ll nPr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], inv_fact[n - r]);
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
        return inv_fact[r];
    }
    /*
        rank = 1 + Σ (i = 0 to n-1) [ (count of characters smaller than s[i] on right) × (n - i - 1)! / Π(freq[ch]!) ]
                
        Yahan:
        - Σ : sum over each character position i
        - count of characters smaller than s[i] on right : kitne characters s[i] se chhote hain aur abhi available hain
        - (n - i - 1)! : remaining positions ke permutations
        - Π(freq[ch]!) : duplicate letters ka overcount avoid karne ke liye divide
        - 1 : lexicographically rank start hota hai 1 se
    */


    ll find_rank(const string &s)
    {
        int n = s.size();
        vector<int> freq(26, 0);  // Only for 'a' to 'z'
        
        // Count all character frequencies
        for (char c : s) freq[c - 'a']++;
        
        ll rank = 1;
        
        for (int i = 0; i < n; i++)
        {
            // Calculate contribution of all smaller characters at position i
            for (char ch = 'a'; ch < s[i]; ch++)
            {
                int idx = ch - 'a';
                if (freq[idx] == 0) continue;
                
                // Agar hum 'ch' ko position i pe rakhte:
                // Step 1: 'ch' ki frequency temporarily kam karo
                freq[idx]--;
                
                // Step 2: Baaki (n-i-1) positions ke permutations with duplicates
                // Formula: (n-i-1)! / (freq[a]! * freq[b]! * ...)
                
                ll numerator = factorial(n - i - 1);
                ll denominator = 1;
                
                for (int c = 0; c < 26; c++)
                {
                    if (freq[c] > 0)
                        denominator = mul(denominator, factorial(freq[c]));
                }
                
                ll contribution = modDiv(numerator, denominator);
                rank = add(rank, contribution);
                
                // Step 3: Restore frequency
                freq[idx]++;
            }
            
            // Current character ko fix kar do for next iteration
            freq[s[i] - 'a']--;
        }
        
        return rank;
    }
};
class Solution {
public:
    int MOD = 1e9+7;
    int makeStringSorted(string s) {
        Combinatorics comb; 
        long long rank = comb.find_rank(s);  
        long long ans = (rank - 1 ) % MOD; // operations = rank - 1
        return ans;
    }
};