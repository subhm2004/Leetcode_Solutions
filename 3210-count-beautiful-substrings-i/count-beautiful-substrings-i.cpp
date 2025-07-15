class Solution {
public:
    bool is_vowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool is_consonant(char ch) {
        ch = tolower(ch);
        return isalpha(ch) &&
               !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int vowels = 0, consonants = 0;

            for (int j = i; j < n; ++j) {
                char ch = s[j];

                if (is_vowel(ch)) vowels++;
                else if (is_consonant(ch)) consonants++;

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
