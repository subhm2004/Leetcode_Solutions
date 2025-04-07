class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto& word : words) {
            // Check if the word starts with the prefix
            if (word.substr(0, pref.size()) == pref) {
                count++;
            }
        }
        return count;
    }
};
