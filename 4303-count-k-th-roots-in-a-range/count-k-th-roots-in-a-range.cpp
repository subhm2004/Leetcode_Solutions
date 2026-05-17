using ll = long long;

class Solution {
public:
    ll mul(ll a, ll b, ll limit) {
        if (a == 0 || b == 0)
            return 0;

        if (a > limit / b)
            return limit + 1;

        return a * b;
    }

    ll fastPower(ll base, int exp, ll limit) {
        ll ans = 1;

        while (exp) {
            if (exp & 1)
                ans = mul(ans, base, limit);

            base = mul(base, base, limit);
            exp >>= 1;
        }

        return ans;
    }

    ll kthRoot_Newton(ll n, int k) {
        if (n < 0)
            return -1;

        if (n == 0 || n == 1)
            return n;

        long double x = (long double)n;
        const long double eps = 1e-15;

        for (int iter = 0; iter < 300; iter++) {
            long double xpow_km1 = powl(x, (long double)(k - 1));

            long double x_next =
                ((long double)(k - 1) * x + (long double)n / xpow_km1) /
                (long double)k;

            if (abs(x - x_next) < eps)
                break;

            x = x_next;
        }

        ll root = (ll)x;

        while (fastPower(root + 1, k, n) <= n)
            root++;

        while (root > 0 && fastPower(root, k, n) > n)
            root--;

        return root;
    }

    int countKthRoots(int l, int r, int k) {
        ll right = kthRoot_Newton((ll)r, k);
        ll left = kthRoot_Newton((ll)l - 1, k);

        return (int)(right - left);
    }
};