class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            if (s.substr(0, word.size()) == word) {
                count++;
            }
        }
        return count;
    }
};
