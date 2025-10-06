class Solution {
public:
    int MOD = 1e9 + 7;

    int countOrders(int n) {
        long long total_ways = 1;
        long long slots = 2 * n;

        for (int i = n; i >= 1; i--) {
            long long ways_for_current = (slots * (slots - 1)) / 2;
            total_ways = (total_ways * ways_for_current) % MOD;
            slots -= 2;
        }

        return (int)total_ways;
    }
};
