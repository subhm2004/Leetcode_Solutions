// class Solution {
// public:
//     int solveRE(int n) {
//         if (n <= 1)  
//             return 1; // Base case: Ek ya zero nodes ke liye sirf ek BST possible hai.

//         int ans = 0;
//         for (int i = 1; i <= n; i++) {  
//             ans += solveRE(i - 1) * solveRE(n - i);
//         }
//         return ans;
//     }

//     int solveME(int n, vector<int>& dp) {
//         if (n <= 1)  
//             return 1; // Base case: Ek ya zero nodes ke liye sirf ek BST possible hai.

//         if (dp[n] != -1)  
//             return dp[n]; // Agar already computed hai, toh use karlo.

//         int ans = 0;
//         for (int i = 1; i <= n; i++) {  
//             ans += solveME(i - 1, dp) * solveME(n - i, dp);
//         }
//         return dp[n] = ans; // Memoization ka use
//     }

//     int numTrees(int n) {
//         vector<int> dp(n + 1, -1); // DP array initialize with -1
//         return solveME(n, dp);
//     }
// };



 // Catlans number se hua hai same recurence relation hai dono ka
class Combinatorics
{
public:
    typedef long long ll;
    const int M = INT_MAX;  
    const int N = 40; // Factorial limit
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
class Solution {
public:
    int numTrees(int n) {
        Combinatorics C;
        long long catalan = C.nCr(2 * n, n);        // C(2n, n)
        catalan = C.modDiv(catalan, n + 1);         // Catalan(n) = C(2n, n) / (n+1)
        return catalan;
    }
};
