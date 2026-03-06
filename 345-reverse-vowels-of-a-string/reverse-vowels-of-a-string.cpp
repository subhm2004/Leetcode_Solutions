class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool is_consonant(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return !is_vowel(c);
        }
        return false; // non-alphabet characters
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            // move i till vowel
            while (i < j && !is_vowel(s[i]))
                i++;

            // move j till vowel
            while (i < j && !is_vowel(s[j]))
                j--;

            // swap vowels
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
