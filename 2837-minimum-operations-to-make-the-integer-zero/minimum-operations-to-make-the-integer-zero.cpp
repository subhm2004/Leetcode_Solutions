class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 0; k <= 60; ++k) {
            long long target = (long long)num1 - (long long)k * num2;
            if (target < 0) continue;
            int bits = __builtin_popcountll(target);
            if (bits <= k && k <= target) return k;  
        }
        return -1;
    }
};
