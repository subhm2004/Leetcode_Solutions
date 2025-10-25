class Solution {
public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        return round((pow(phi, n) - pow(psi, n)) / sqrt5);
    }
};