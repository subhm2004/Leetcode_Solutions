class Solution {
public:
    int reversed_number(int n) {
        int rev = 0;
        while(n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        int reversed = reversed_number(n);
        return abs(n - reversed);
    }
};