class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> pewfix_count;

        // count each prefix
        for (string &word : words) {
            if (word.length() >= k) {
                string prefix = word.substr(0, k);
                pewfix_count[prefix]++;
            }
        }

        // count karte hai valid groups ko 
        int groups = 0;
        for (auto &it : pewfix_count) {
            if (it.second >= 2) {
                groups++;
            }
        }

        return groups;
    }
};