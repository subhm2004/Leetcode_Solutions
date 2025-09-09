class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string s) {
        int vowel_count = 0;

        // Step 1: Count the number of vowels in the string
        for (char &c : s) {
            if (is_vowel(c)) {
                vowel_count++;
            }
        }

        // Step 2: Alice wins if there is at least one vowel
        return vowel_count > 0;
    }
};
