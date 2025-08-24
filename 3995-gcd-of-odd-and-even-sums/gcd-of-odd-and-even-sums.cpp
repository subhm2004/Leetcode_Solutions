class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
// gcd(sumOdd,sumEven)= gcd(n^2,n(n+1)) = =n⋅gcd(n,n+1) as gcd(n,n+1) == 1 so result is n.
