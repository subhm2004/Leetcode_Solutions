class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<32> bits(n);

        int pairs = 0;

        for (int i = 0; i < 31; i++) {
            if (bits[i] && bits[i + 1]) {
                pairs++;
            }
        }

        return pairs == 1;
    }
};