class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char digit = x + '0';

        // number should not start with x
        if (s[0] == digit) return false;

        // number should contain at least one x
        return s.find(digit) != string::npos;
    }
};