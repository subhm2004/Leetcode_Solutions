class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        long long end_[26] = {0}, total = 0;   // total = sum of end_[]

        for (char ch : s) {
            int c = ch - 'a';
            long long add = (total - end_[c] + 1 + MOD) % MOD;  // delta, avoids recomputing sum
            end_[c] = (end_[c] + add) % MOD;
            total   = (total   + add) % MOD;
        }
        return (int)total;
    }
};