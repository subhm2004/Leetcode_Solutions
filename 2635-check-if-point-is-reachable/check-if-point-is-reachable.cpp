class Solution {
public:
    // a * b = lcm(a,b) * hcf(a,b)
    // hcf or gcd dono same hota hai
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool isReachable(int targetX, int targetY) {
        long long g = gcd(targetX, targetY);
        return (g & (g - 1)) == 0;
    }
};