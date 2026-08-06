class Solution {
public:
    int digits_ka_product(int x) {
        int product = 1;
        while (x > 0) {
            int digit = x % 10;
            product *= digit;
            x /= 10;
        }
        return product;
    }
    
    int smallestNumber(int n, int t) {
        while (true) {
            if (n == 0) {
                return (t == 1) ? 0 : t;
            }
            if (digits_ka_product(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};
