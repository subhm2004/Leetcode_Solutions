class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool doesAliceWin(string s) {
        int vowelCount = 0;

        // Step 1: Count the number of vowels in the string
        for (char c : s) {
            if (isVowel(c)) {
                vowelCount++;
            }
        }

        // Step 2: Alice wins if there is at least one vowel
        return vowelCount > 0;
    }
};
