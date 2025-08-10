class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end()); // smallest lexicographic arrangement
        do {
            if (s[0] != '0') { // leading zero check
                int num = stoi(s);
                if (__builtin_popcount(num) == 1) // power of 2 check
                    return true;
            }
        } while (next_permutation(s.begin(), s.end())); // generate all permutations
        return false;
    }
};
