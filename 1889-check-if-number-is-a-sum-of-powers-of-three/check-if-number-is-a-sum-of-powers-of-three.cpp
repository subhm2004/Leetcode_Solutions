class Solution {
public:
    bool checkPowersOfThree(int n) {
        long power = 1;
        
        // Find the smallest power of 3 that is ≥ n
        for (int i = 0; power < n; i++) {
            power = pow(3, i);
        }

        // Try subtracting distinct powers of 3
        for (; power > 0; power /= 3) {
            if (n >= power) {
                n -= power;
            }
        }

        return n == 0;
    }
};