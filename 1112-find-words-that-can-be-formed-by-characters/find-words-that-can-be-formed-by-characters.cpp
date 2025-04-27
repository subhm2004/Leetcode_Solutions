class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount;
        for (char c : chars)
            charCount[c]++;

        int totalLength = 0;
        for (auto& word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word)
                wordCount[c]++;

            bool canForm = true;
            for (auto& [ch, freq] : wordCount) {
                if (charCount[ch] < freq) {
                    canForm = false;
                    break;
                }
            }

            if (canForm)
                totalLength += word.size();
        }

        return totalLength;
    }
};
