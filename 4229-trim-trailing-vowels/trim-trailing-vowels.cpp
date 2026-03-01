class Solution {
public:
    bool is_vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string trimTrailingVowels(string s) {
        int i = s.size() - 1;

        while (i >= 0 && is_vowel(s[i])) {
            i--;
        }

        return s.substr(0, i + 1);
    }
};