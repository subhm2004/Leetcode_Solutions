class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            words.push_back(word);  
            i++;  
        }

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;

        for (int i = 0; i < pattern.size(); ++i) {
            char ch = pattern[i];
            string w = words[i];

            if (char_to_word.count(ch)) {
                if (char_to_word[ch] != w) return false;
            } else {
                if (word_to_char.count(w)) return false;

                char_to_word[ch] = w;
                word_to_char[w] = ch;
            }
        }

        return true;
    }
};
