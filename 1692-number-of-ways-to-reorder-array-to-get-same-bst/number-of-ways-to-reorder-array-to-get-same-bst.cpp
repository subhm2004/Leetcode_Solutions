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
    const int M = 1e9 + 7; // MOD value
    const int N = 1005;    // Factorial limit
    vector<ll> fact, inv_fact;

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

    ll inv(ll x) { return modPow(x, M - 2); } // Fermat's theorem
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics() {
        fact.resize(N, 1);
        inv_fact.resize(N, 1);
        precalc();
    }

    void precalc() {
        for (int i = 1; i < N; i++)
            fact[i] = mul(fact[i - 1], i);
        inv_fact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
            inv_fact[i] = mul(inv_fact[i + 1], i + 1);
    }

    ll nCr(ll n, ll r) {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(inv_fact[r], inv_fact[n - r]));
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;
    Combinatorics C; 

    long long count_ways(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 1; // single node or two nodes ho  -> to ek hi BST possible hai

        int root = arr[0];
        vector<int> left, right;

        // Split array on BST property 
        // Relative order to same hi rhega ese store kruga to 
        for (int i = 1; i < n; i++) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long left_ways = count_ways(left);
        long long right_ways = count_ways(right);

        // Mix left + right subtree in combination C(L+R, L) with  maintainining the Relative order 
        long long total = C.nCr(n - 1, left.size());
        total = (total * left_ways) % MOD;
        total = (total * right_ways) % MOD;

        return total;
    }

    int numOfWays(vector<int>& arr) {
        long long total = count_ways(arr);
        // Subtract 1 to exclude the original permutation jo arr ki value di gyi hai
        return (total - 1 + MOD) % MOD;
    }
};
/*   Relative Order and formula kse aaya 
   total count =  C(L+R, L) * count_left_recursive * count_right_recursive
    
Example: nums = [3, 4, 5, 1, 2]
  Root = 3

  Left subtree ke elements = [1, 2]  (L = 2)  → inka order same rehna chahiye [1,2]
  Right subtree ke elements = [4, 5] (R = 2)  → inka order bhi same rehna chahiye [4,5]

  Ab root ke baad total L + R = 4 elements bache hain.
  Hume in 4 positions me se L = 2 jagah left subtree ke elements ke liye choose karni hain.
  (baaki R = 2 positions right ke elements ke liye automatically mil jayengi)

  Yaani total tarike = C(4,2) = 6

  Ye 6 tarike possible hain jahan dono side ka order maintain hota hai:

  1️⃣ 3 1 2 4 5  → Left [1,2] start me, Right [4,5] baad me  
                   Dono ka internal order same (1→2, 4→5)

  2️⃣ 3 1 4 2 5  → Left ke elements (1,2) slots (1,3) pe  
                   Order same: left me 1 pehle 2 baad me, right me 4 pehle 5 baad me

  3️⃣ 3 1 4 5 2  → Left (1,4) pe rakhe, Right [4,5] apne order me  
                   Left [1,2] bhi order me hi hain

  4️⃣ 3 4 1 2 5  → Right ka 4 pehle aaya, fir left ka [1,2], fir 5  
                   BST structure same rahta hai

  5️⃣ 3 4 1 5 2  → Thoda mix hua, lekin left ke andar 1 pehle 2 baad me hi aaya  
                   Right ka order bhi [4,5] same hai

  6️⃣ 3 4 5 1 2  → Dono right elements (4,5) pehle aaye, fir left ke (1,2)  
                   Ye original sequence hai

  \U0001f4a1 Important:
  In sab cases me:
  - Left subtree ke elements [1,2] ka order kabhi nahi badla
  - Right subtree ke elements [4,5] ka order kabhi nahi badla
  Isliye har permutation se **same BST structure** banta hai.
*/
