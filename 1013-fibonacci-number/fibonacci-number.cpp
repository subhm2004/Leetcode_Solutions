class Solution {
public:
    int fib(int N) {
        const double sqrt_5 = sqrt(5);
        const double phi = (1 + sqrt_5) / 2;
        return (pow(phi, N) / sqrt_5) + 0.5;
    }
};