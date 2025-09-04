class Solution {
public:
    bool non_zero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (non_zero(a) && non_zero(b)) {
                return {a, b};
            }
        }
        return {}; // kabhi nhi hoga
    }
};