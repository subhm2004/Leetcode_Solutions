class Solution {
public:
    bool is_vowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isValid(string word) {
        if (word.length() < 3)
            return false;

        bool vowel = false;
        bool consonant = false;

        for (char ch : word) {
            if (!isalpha(ch) && !isdigit(ch))
                return false;

            if (isalpha(ch)) {
                if (is_vowel(ch)) {
                    vowel = true;
                } else {
                    consonant = true;
                }
            }
        }

        return vowel && consonant;
    }
};
