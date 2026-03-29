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

        int left = pos;
        int right = n - pos - 1;

        long long ans = 0;
        /*
    Let:
    left  = number of people on left side
    right = number of people on right side
    k     = total visible people

    We choose:
    x     = number of visible people from left
    k-x   = number of visible people from right

    So:
    x + (k-x) = k  

// har ek x k liye way = C(left,x) * C(right,k−x) 

    1) LEFT SIDE CONSTRAINT:
       Left side me total 'left' log hain
       x <= left

       Also total visible k hai:
       x <= k

        x <= min(left, k)

    -------------------------------

    2) RIGHT SIDE CONSTRAINT:
       Right side se (k-x) log visible honge
       But right me total 'right' log hi hain

       (k - x) <= right

       Solve:
       k - x <= right
       x >= k - right

    

    3) NON-NEGATIVE CONSTRAINT:
       x >= 0  (count negative nahi ho sakta)


    FINAL RANGE:

    x >= max(0, k - right)
    x <= min(left, k)

     x ∈ [ max(0, k - right), min(left, k) ]

    */
        for (int x = max(0, k - right); x <= min(left, k); x++) {
            long long left_ways = comb.nCr(left, x);
            long long right_ways = comb.nCr(right, k - x);

            ans = (ans + (left_ways * right_ways) % MOD) % MOD;
        }
        // pos wala banda free hai kha ajna hai use to wo ja skta h khi bhi left
        // ya right me soo ans ko 2 se multiply kiya hai

        return (2 * ans) % MOD;
    }
};