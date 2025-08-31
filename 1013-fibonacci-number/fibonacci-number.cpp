class Solution {
public:
    int fib(int N) {
        const double sqrt5 = sqrt(5);
        const double phi = (1 + sqrt5) / 2;
        return static_cast<int>((pow(phi, N) / sqrt5) + 0.5);
    }
};