class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;

        long long ans = LLONG_MAX;

        auto compute = [&](long long x) {
            long long r1 = max(0LL, need1 - x);
            long long r2 = max(0LL, need2 - x);
            return x * costBoth + r1 * cost1 + r2 * cost2;
        };

        ans = min(ans, compute(0));
        ans = min(ans, compute(min(need1, need2)));
        ans = min(ans, compute(max(need1, need2)));

        return ans;
    }
};