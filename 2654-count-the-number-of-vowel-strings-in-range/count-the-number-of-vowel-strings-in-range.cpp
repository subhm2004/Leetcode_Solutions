class Solution {
public:
    bool startsAndEndsWithVowel(string& word) {
        string vowels = "aeiouAEIOU";

        if (word.empty()) return false;

        char first = word.front();
        char last = word.back();

        return vowels.find(first) != string::npos && vowels.find(last) != string::npos;
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;

        // Left se right tak loop lagao
        for (int i = left; i <= right; ++i) {
            if (startsAndEndsWithVowel(words[i])) {
                count++;  
            }
        }

        return count;
    }
};
