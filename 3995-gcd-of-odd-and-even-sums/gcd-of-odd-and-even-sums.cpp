class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        /*
            Sum of first n odd numbers  = n^2
            Sum of first n even numbers = n(n + 1)

            gcd(odd_sum, even_sum)
            = gcd(n^2, n(n + 1))
            = n * gcd(n, n + 1)

            Since gcd(n, n + 1) = 1 (consecutive numbers are always coprime),

            gcd(odd_sum, even_sum) = n
        */
        return n;
    }
};