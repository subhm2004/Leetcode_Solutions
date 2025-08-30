typedef long long ll;

class Solution {
public:
    int MOD = 1e9 + 7;

    int minOperations(string s, int k) {
        int n = s.size();
        int zeros = 0;

        for (auto ch : s) {
            if (ch == '0')
                zeros++;
        }

        if (zeros == 0)
            return 0;

        int min_zeros_rechable = zeros, max_zeros_rechable = zeros;

        for (int i = 1; i <= n + 1; i++) {
            int nxt_max_zeros, nxt_min_zeros;

            if (min_zeros_rechable <= k && k <= max_zeros_rechable) {
                nxt_min_zeros = 0;
            }
            else {
                nxt_min_zeros = min(abs(min_zeros_rechable - k), abs(max_zeros_rechable - k));
            }

            if (min_zeros_rechable <= n - k && n - k <= max_zeros_rechable) {
                nxt_max_zeros = n;
            } else {
                int a = n - abs(n - (min_zeros_rechable + k));
                int b = n - abs(n - (max_zeros_rechable + k));
                nxt_max_zeros = max(a, b);
            }

            min_zeros_rechable = nxt_min_zeros;
            max_zeros_rechable = nxt_max_zeros;

            bool is_parity = (zeros + (ll)i * k) % 2 == 0;

            if (is_parity && min_zeros_rechable <= 0 && 0 <= max_zeros_rechable)
                return i;
        }

        return -1;
    }
};
