class Solution {
public:
    int findComplement(int num) {

        int bits = 32 - __builtin_clz(num);

        int mask = (1LL << bits) - 1;

        return num ^ mask;
    }
};