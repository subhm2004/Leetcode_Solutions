class Solution {
public:
    int findComplement(int num) {

        int bits = 32 - __builtin_clz(num);

        int mask = (1LL << bits) - 1;

        return num ^ mask;
    }
};

/**
 * num = 5 = "101" (binary)
 *
 * STEP 1: Significant bits nikalo
 *   __builtin_clz(5) = 29 (leading zeros)
 *   bits = 32 - 29 = 3
 *
 * STEP 2: Mask banao (utni 1s jitni bits)
 *   (1LL << 3) - 1 = 8 - 1 = 7 = "111"
 *
 * STEP 3: XOR karo (har bit flip)
 *   101 (5)
 * ^ 111 (7)
 * -------
 *   010 = 2 
 */