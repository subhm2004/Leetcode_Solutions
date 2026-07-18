class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;

        long long peaks = n / 2;

        return 1LL * s + m + 1LL * (peaks - 1) * (m - 1);
    }
};