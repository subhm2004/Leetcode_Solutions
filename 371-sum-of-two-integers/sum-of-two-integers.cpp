class Solution {
public:
    int solve(int a, int b) {
        if (b == 0)
            return a;
        return solve(a ^ b, (a & b) << 1);
    }
    int getSum(int a, int b) { return solve(a, b); }
};