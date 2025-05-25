class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;

        for (string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());   

            if (freq[rev] > 0) {
                length += 4;        // matched pair: add 4 to length
                freq[rev]--;        // use one reversed pair
            } else {
                freq[word]++;       // store this word for future matching
            }
        }

        // check for a word like "aa", "bb", etc., for the center
        for (auto& it : freq) {
            string word = it.first;
            if (word[0] == word[1] && it.second > 0) {
                length += 2;  // place one such word in the center
                break;
            }
        }

        return length;
    }
};
