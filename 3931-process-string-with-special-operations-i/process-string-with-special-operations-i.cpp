class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (ch == '*') {
                if (!result.empty()) result.pop_back(); // Remove last char
            } else if (ch == '#') {
                result += result; // Duplicate result
            } else if (ch == '%') {
                reverse(result.begin(), result.end()); // Reverse result
            } else {
                result.push_back(ch); // It's a lowercase letter
            }
        }

        return result;
    }
};
