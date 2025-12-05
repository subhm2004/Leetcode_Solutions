class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int bits = (int)log2(i) + 1; // i ke binary me kitne bits

            // ans ko bits ke hisab se left shift karo
            ans = (ans * (1LL << bits)) % MOD;

            // ab i ko add kar do
            ans = (ans + i) % MOD;
        }

        return ans;
    }
};
