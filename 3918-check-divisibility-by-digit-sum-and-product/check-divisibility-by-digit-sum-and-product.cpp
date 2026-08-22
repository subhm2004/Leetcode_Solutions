class Solution {
public:
    int digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int digit_product(int n) {
        int pro = 1;
        while (n > 0) {
            int digit = n % 10;
            pro *= digit;
            n /= 10;
        }
        return pro;
    }
 
    bool checkDivisibility(int n) {
        int sum = digit_sum(n);
        int product = digit_product(n);
        int total = sum + product;
        return (total != 0 && n % total == 0);
    }
};