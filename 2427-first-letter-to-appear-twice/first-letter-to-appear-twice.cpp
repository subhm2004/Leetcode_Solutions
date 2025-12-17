class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;

            // jaise hi kisi character ka count 2 ho,
            // wahi first repeated character hai
            if (freq[ch - 'a'] == 2) {
                return ch;
            }
        }
        return '\0'; // null char 
    }
};
