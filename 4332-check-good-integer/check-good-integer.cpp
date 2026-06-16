class Solution {
public:
    bool checkGoodInteger(int n) {
        int digit_sum = 0;
        int square_sum = 0;
        while (n > 0) {
            int d = n % 10;
            digit_sum += d;
            square_sum += d * d;
            n /= 10;
        }
        return square_sum - digit_sum >= 50;
    }
};