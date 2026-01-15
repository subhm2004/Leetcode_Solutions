class Solution {
public:
    int minChanges(int n, int k) {

        if ((n & k) != k)
            return -1;

        int diff = (n ^ k) & n;

        return __builtin_popcount(diff);
    }
};
