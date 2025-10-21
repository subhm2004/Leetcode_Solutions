class Solution {
public:
    bool hasSameDigits(string s) {
        // Base case: when only 2 digits remain
        if (s.size() == 2)
            return s[0] == s[1];

        string next = "";
        for (int i = 0; i + 1 < s.size(); ++i) {
            int sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
            next = next + char(sum + '0');  
        }

        // Recursive call on the smaller string
        return hasSameDigits(next);
    }
};