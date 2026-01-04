class Solution {
public:
    string largestEven(string s) {
        int last_2 = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '2') {
                last_2 = i;
            }
        }

        if (last_2 == -1)
            return "";

        return s.substr(0, last_2 + 1);
    }
};