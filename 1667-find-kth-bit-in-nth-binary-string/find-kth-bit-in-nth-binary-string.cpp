class Solution {
public:
    char solve(int n, int k) {
        if (n == 1)
            return '0';

        int mid = (1 << (n - 1)); // 2^(n-1)

        if (k == mid)
            return '1'; // Middle bit is always '1'

        if (k < mid)
            return findKthBit(n - 1, k); // Left part: same as S_(n-1)

        // Right part: mirrored and inverted
        return findKthBit(n - 1, mid * 2 - k) == '0' ? '1' : '0';
    }
    char findKthBit(int n, int k) { return solve(n, k); }
};