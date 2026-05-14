class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        // Step 1: build string
        string s = "";
        for (auto &c : chunks) s += c;

        unordered_map<string, int> freq;
        string word = "";

        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            bool isLetter = (ch >= 'a' && ch <= 'z');

            bool isJoinerHyphen = false;
            if (ch == '-' && i > 0 && i < n - 1) {
                if (islower(s[i - 1]) && islower(s[i + 1])) {
                    isJoinerHyphen = true;
                }
            }

            if (isLetter || isJoinerHyphen) {
                word += ch;
            } else {
                if (!word.empty()) {
                    freq[word]++;
                    word = "";
                }
            }
        }

        // last word
        if (!word.empty()) {
            freq[word]++;
        }

        // Step 2: answer queries
        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
    }
};