class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // move i till vowel
            while (i < j && !isVowel(s[i])) i++;

            // move j till vowel
            while (i < j && !isVowel(s[j])) j--;

            // swap vowels
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
