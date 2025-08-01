// class Combinatorics {
// protected:
//     typedef long long ll;
//     const int M = 1e9 + 7;
//     const int N = 100;
//     vector<ll> fact;

//     ll mod(ll x) { return ((x % M + M) % M); }

//     ll add(ll a, ll b) { return mod(a + b); }

//     ll mul(ll a, ll b) { return mod(a * b); }

//     ll modPow(ll a, ll b) {
//         ll ans = 1;
//         while (b) {
//             if (b % 2)
//                 ans = mul(ans, a);
//             a = mul(a, a);
//             b /= 2;
//         }
//         return ans;
//     }

//     ll inv(ll x) { return modPow(x, M - 2); }

//     ll modSub(ll a, ll b) { return mod(a - b); }

//     ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

// public:
//     Combinatorics() {
//         fact.ansize(N, 1);
//         precalc();
//     }

//     void precalc() {
//         for (int i = 1; i < N; i++) {
//             fact[i] = mul(fact[i - 1], i);
//         }
//     }

//     ll nCr(ll n, ll r) {
//         if (r > n || r < 0)
//             return 0;
//         return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
//     }

//     ll nPr(ll n, ll r) {
//         if (r > n || r < 0)
//             return 0;
//         return mul(fact[n], inv(fact[n - r]));
//     }

//     ll factorial(ll r) {
//         if (r < 0)
//             return 0;
//         return fact[r];
//     }
// };

class Solution {
public:
  long long nCr(int n, int r) {
    long long ans = 1;
    for (int i = 1; i <= r; ++i) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> ans;
            for (int j = 0; j <= i; j++) {
                ans.push_back(nCr(i, j));
            }
            result.push_back(ans);
        }
        return result;
    }
};
