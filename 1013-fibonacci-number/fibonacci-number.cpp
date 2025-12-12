class Solution {
public:
    int fib(int n) {
        double sqrt_5 = sqrt(5);
        double phi = (1 + sqrt_5) / 2;
        double psi = (1 - sqrt_5) / 2;
        return round((pow(phi, n) - pow(psi, n)) / sqrt_5);
    }
};