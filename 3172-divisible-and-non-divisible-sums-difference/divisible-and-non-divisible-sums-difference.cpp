class Solution {
public:
    int sum_Not_Divisible(int p, int q) {
        int sum = 0;
        for (int i = 1; i <= p; ++i) {
            if (i % q != 0) { // Check if number is not divisible by q
                sum += i;
            }
        }
        return sum;
    }

    int sum_Divisible(int p, int q) {
        int sum = 0;
        for (int i = 1; i <= p; ++i) {
            if (i % q == 0) { // Check if number is divisible by q
                sum += i;
            }
        }
        return sum;
    }
    int differenceOfSums(int n, int m) {
        int num1 = sum_Not_Divisible(n, m);
        int num2 = sum_Divisible(n, m);
        return num1 - num2;
    }
};