class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0) return 1;
        int bits = 32 - __builtin_clz(num);

        int mask = (1LL << bits) - 1;

        return num ^ mask;
    }
};