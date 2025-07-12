class Solution {
public:
    double binary_Expo_Iterative(double a, long long b) {
        bool is_negative = (b < 0);
        if (is_negative)
            b = -b;

        double result = 1.0;
        while (b > 0) {
            if (b & 1)
                result *= a;
            a *= a;
            b >>= 1;
        }

        return is_negative ? 1.0 / result : result;
    }
    double myPow(double x, int n) {
        return binary_Expo_Iterative(x,n);
    }
};