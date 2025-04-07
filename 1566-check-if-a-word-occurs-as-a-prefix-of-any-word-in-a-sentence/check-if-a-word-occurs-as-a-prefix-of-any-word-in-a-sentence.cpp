class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        int n = sentence.length();
        int searchLen = searchWord.length();
        for (int i = 0; i < n; ++i) {
            if (sentence.substr(i, searchLen) == searchWord &&
                (i == 0 || sentence[i - 1] == ' ')) {
                return index;
            }
            if (sentence[i] == ' ') {
                ++index;
            }
        }
        return -1;
    }
};
