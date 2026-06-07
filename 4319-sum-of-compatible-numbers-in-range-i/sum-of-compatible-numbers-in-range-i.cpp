/*
abs(n - x) <= k
then
-k <= n - x <= k

From the left inequality:
-k <= n - x
x - k <= n
x <= n + k

From the right inequality:
n - x <= k
n <= x + k
n - k <= x

Combining both results:

n - k <= x <= n + k

Since x is a positive integer:

max(1, n - k) <= x <= n + k
*/
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;

        for (int x = max(1, n - k); x <= n + k; x++) {
            if ((n & x) == 0) {
                sum += x;
            }
        }

        return sum;
    }
};