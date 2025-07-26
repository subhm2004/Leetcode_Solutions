class Solution {
public:
    bool strongPasswordCheckerII(string str) {
        if (str.length() < 8) return false;

        bool has_lower = false;
        bool has_upper = false;
        bool has_digit = false;
        bool has_special_char = false;

        string special_char = "!@#$%^&*()-+";

        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];

            if (i > 0 && str[i] == str[i - 1])
                return false; // same adjacent characters

            if (islower(ch)) has_lower = true;
            else if (isupper(ch)) has_upper = true;
            else if (isdigit(ch)) has_digit = true;
            else if (special_char.find(ch) != string::npos) has_special_char = true;
        }

        return has_lower && has_upper && has_digit && has_special_char;
    }
};
