class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        int index = 0;

        while (n > 0) {
            if (n & 1) {
                if (index % 2 == 0)
                    ++even;
                else
                    ++odd;
            }
            ++index;
            n >>= 1; // Right shift to check next bit
        }

        return {even, odd};
    }
};