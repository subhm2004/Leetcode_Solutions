class Solution {
public:
    int solveRE(int remainder, int len, int k) {
        // agar divisible mil gaya
        if (remainder == 0) {
            return len;
        }

        // agar k se zyada digits ho gaye -> cycle
        if (len > k) {
            return -1;
        }

        int new_remainder = (remainder * 10 + 1) % k;
        return solveRE(new_remainder, len + 1, k);
    }
    int minAllOneMultiple(int k) { return solveRE(1 % k, 1, k); }
};