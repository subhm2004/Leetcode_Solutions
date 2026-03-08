class Solution {
public:
    int sum_of_proper_divisors(int n) {
        if (n <= 1)
            return 0;
        int sum = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i == n)
                    sum += i;
                else
                    sum += i + n / i;
            }
        }
        return sum;
    }
    int sum_of_divisors(int n) { return sum_of_proper_divisors(n) + n; }
    bool checkPerfectNumber(int num) {
        return sum_of_proper_divisors(num) == num;
    }
};